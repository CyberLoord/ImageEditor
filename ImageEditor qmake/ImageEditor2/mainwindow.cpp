#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), imageLabel(new QLabel(this)), toolbar(new QToolBar(this)),
        scaleAction(new QAction(tr("&Change Scale"), this)),
        horizontalStretchAction(new QAction(tr("&Horizontal Stretch"), this)),
        verticalStretchAction(new QAction(tr("&Vertical Stretch"), this)),
        scaleFactor(1.0), isScaling(false), isMoving(false), isResizing(false), isImageModified(false)
{
    imageLabel->setScaledContents(true);
    setCentralWidget(imageLabel);

    lastImagesList = new imagesList();
    camWindow = new cameraWindow();

    toolbar->addAction(tr("&Open"), this, &MainWindow::openImage);
    toolbar->addAction(tr("&Last Images"), this, &MainWindow::openLastImagesList);
    toolbar->addAction(tr("&Photograph"), this, &MainWindow::openCamWindow);
    toolbar->addAction(tr("&Save As"), this, &MainWindow::saveImage);
    toolbar->addAction(scaleAction);
    toolbar->addAction(horizontalStretchAction);
    toolbar->addAction(verticalStretchAction);
    toolbar->addAction(tr("&Undo"), this, &MainWindow::undo);
    addToolBar(toolbar);

    scaleAction->setCheckable(true);
    horizontalStretchAction->setCheckable(true);
    verticalStretchAction->setCheckable(true);

    ctrlO = new QShortcut(this);
    ctrlO->setKey(Qt::CTRL + Qt::Key_O);
    ctrlS = new QShortcut(this);
    ctrlS->setKey(Qt::CTRL + Qt::Key_S);
    ctrlZ = new QShortcut(this);
    ctrlZ->setKey(Qt::CTRL + Qt::Key_Z);
    ctrlL = new QShortcut(this);
    ctrlL->setKey(Qt::CTRL + Qt::Key_L);
    ctrlP = new QShortcut(this);
    ctrlP->setKey(Qt::CTRL + Qt::Key_P);

    connect(ctrlO, SIGNAL(activated()), this, SLOT(slotShortcutCtrlO()));
    connect(ctrlS, SIGNAL(activated()), this, SLOT(slotShortcutCtrlS()));
    connect(ctrlZ, SIGNAL(activated()), this, SLOT(slotShortcutCtrlZ()));
    connect(ctrlL, SIGNAL(activated()), this, SLOT(slotShortcutCtrlL()));
    connect(ctrlP, SIGNAL(activated()), this, SLOT(slotShortcutCtrlP()));
    connect(lastImagesList, &imagesList::mainWindow, this, &MainWindow::show);
    connect(lastImagesList, &imagesList::signalOpenImage, this, &MainWindow::slotOpenImage);
    connect(camWindow, &cameraWindow::signalOpenImage, this, &MainWindow::slotOpenImage);
    connect(scaleAction, &QAction::triggered, this, [this]() { scaleImage(scaleAction->isChecked() ? 1.0 : 0.0); });
    connect(horizontalStretchAction, &QAction::triggered, this, &MainWindow::stretchImageHorizontal);
    connect(verticalStretchAction, &QAction::triggered, this, &MainWindow::stretchImageVertical);

    originalImage = QImage();
    modifiedImage = originalImage;

    updateDisplay();
}

void MainWindow::openLastImagesList()
{
    lastImagesList->show();
}

void MainWindow::openCamWindow()
{
    camWindow->show();
}

void MainWindow::insertImage(QImage image)
{
    imageVersions.clear();

    int maxDisplayWidth = centralWidget()->width() * 3 / 4;
    int maxDisplayHeight = centralWidget()->height() * 3 / 4;

    qreal widthFactor = static_cast<qreal>(maxDisplayWidth) / image.width();
    qreal heightFactor = static_cast<qreal>(maxDisplayHeight) / image.height();

    scaleFactor = qMin(widthFactor, heightFactor);

    int displayWidth = static_cast<int>(image.width() * scaleFactor);
    int displayHeight = static_cast<int>(image.height() * scaleFactor);

    originalImage = image.scaled(displayWidth, displayHeight, Qt::KeepAspectRatio);
    modifiedImage = originalImage;

    updateDisplay();
}

void MainWindow::slotOpenImage(QPixmap pixmapImage)
{
    QImage image;
    image = pixmapImage.toImage();

    insertImage(image);
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "",
                                                    tr("Image Files (*.png *.jpg *.bmp *.jpeg *.gif)"));

    if (fileName.isEmpty()) {
        return;
    }

    QImage image(fileName);

    if (image.isNull()) {
        QMessageBox::information(this, tr("Image Editor"),
                                 tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        return;
    }

    insertImage(image);
}

void MainWindow::saveImage()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("Save Image"));
    msgBox.setText(tr("Do you want to save only the changed image?"));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::SaveAll | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setIcon(QMessageBox::Question);

    int answer = msgBox.exec();

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (fileName.isEmpty()) {
        return;
    }

    QImage savedImage;
    QPixmap currentPixmap = imageLabel->pixmap(Qt::ReturnByValue);
    QPixmap croppedPixmap;

    if (answer == QMessageBox::Save) {
        int displayX = (centralWidget()->width() - modifiedImage.width()) / 2;
        int displayY = (centralWidget()->height() - modifiedImage.height()) / 2;

        croppedPixmap = currentPixmap.copy(displayX, displayY, modifiedImage.width(), modifiedImage.height());
        savedImage = croppedPixmap.toImage();
    } else if (answer == QMessageBox::SaveAll) {
        savedImage = currentPixmap.toImage();
    }

    if (!savedImage.isNull() && answer != QMessageBox::Cancel) {
        if (!savedImage.save(fileName)) {
            QMessageBox::information(this, tr("Image Editor"),
                                     tr("Cannot save %1.").arg(QDir::toNativeSeparators(fileName)));
        }
        if (answer == QMessageBox::Save) {
            lastImagesList->saveImageToDB(croppedPixmap);
        } else {
            lastImagesList->saveImageToDB(currentPixmap);
        }
    }
}

void MainWindow::scaleImage(qreal factor)
{
    if (isScaling) {
        isScaling = false;
        scaleFactor = 1.0;
        imageLabel->setCursor(Qt::ArrowCursor);
    } else {
        imageVersions.push(modifiedImage);

        isScaling = true;
        scaleFactor = factor;
        imageLabel->setCursor(Qt::SizeAllCursor);

        originalImage = modifiedImage;
    }

    updateDisplay();
}


void MainWindow::stretchImageHorizontal()
{
    if (horizontalStretchAction->isChecked()) {
        imageVersions.push(modifiedImage);
        verticalStretchAction->setChecked(false);
        isResizing = true;
        imageLabel->setCursor(Qt::SizeHorCursor);
    } else {
        isResizing = false;
        imageLabel->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::stretchImageVertical() {
    if (verticalStretchAction->isChecked()) {
        imageVersions.push(modifiedImage);
        horizontalStretchAction->setChecked(false);
        isResizing = true;
        imageLabel->setCursor(Qt::SizeVerCursor);
    } else {
        isResizing = false;
        imageLabel->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::undo()
{
    if (!imageVersions.isEmpty()) {
        modifiedImage = imageVersions.pop();
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::mirrorImage()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        modifiedImage = modifiedImage.mirrored(true, false);
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::blurPro(int radius)
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        for (int y = radius; y < modifiedImage.height() - radius; y++) {
            for (int x = radius; x < modifiedImage.width() - radius; x++) {
                int totalRed = 0;
                int totalGreen = 0;
                int totalBlue = 0;
                int pixelsCount = 0;

                for (int dy = -radius; dy < radius + 1; dy++) {
                    for (int dx = -radius; dx < radius + 1; dx++) {
                        QColor pixelColor = QColor(modifiedImage.pixel(x + dx, y + dy));
                        totalRed += pixelColor.red();
                        totalGreen += pixelColor.green();
                        totalBlue += pixelColor.blue();
                        pixelsCount++;
                    }
                }
                int averageRed = totalRed / pixelsCount;
                int averageGreen = totalGreen / pixelsCount;
                int averageBlue = totalBlue / pixelsCount;

                modifiedImage.setPixelColor(x, y, QColor(averageRed, averageGreen, averageBlue));
            }
        }
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::grayscale()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        modifiedImage = modifiedImage.convertToFormat(QImage::Format_Grayscale8);
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::sepiaTone()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        for (int y = 0; y < modifiedImage.height(); y++) {
            for (int x = 0; x < modifiedImage.width(); x++) {
                QRgb pixel = modifiedImage.pixel(x, y);
                int R = qRed(pixel);
                int G = qGreen(pixel);
                int B = qBlue(pixel);

                int newR = qBound(0, static_cast<int>(0.393 * R + 0.769 * G + 0.189 * B), 255);
                int newG = qBound(0, static_cast<int>(0.349 * R + 0.686 * G + 0.168 * B), 255);
                int newB = qBound(0, static_cast<int>(0.272 * R + 0.534 * G + 0.131 * B), 255);

                modifiedImage.setPixel(x, y, qRgb(newR, newG, newB));
            }
        }
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::sharpenImage()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        QImage newImage = modifiedImage;
        std::vector <std::vector<int>>convolutionMatrix;
        convolutionMatrix.resize(3, std::vector<int>(3));
        convolutionMatrix[0][1] = -1, convolutionMatrix[1][0] = -1, convolutionMatrix[1][1] = 5, convolutionMatrix[1][2] = -1, convolutionMatrix[2][1] = -1;

        for (size_t y = 1; y < modifiedImage.height() - convolutionMatrix.size() / 2; y++) {
            for (size_t x = 1; x < modifiedImage.width() - convolutionMatrix.size() / 2; x++) {
                int red = 0;
                int green = 0;
                int blue = 0;

                for (size_t t = 0; t < convolutionMatrix.size(); t++) {
                    for (size_t p = 0; p < convolutionMatrix.size(); p++) {
                        QColor pixelColor = QColor(modifiedImage.pixel(x + p - 1, y + t - 1));
                        red += pixelColor.red() * convolutionMatrix[t][p];
                        green += pixelColor.green() * convolutionMatrix[t][p];
                        blue += pixelColor.blue() * convolutionMatrix[t][p];
                    }
                }
                newImage.setPixelColor(x, y, QColor(qBound(0, red, 255), qBound(0, green, 255), qBound(0, blue, 255)));
            }
        }
        modifiedImage = newImage;
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::сontrast(int factor)
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        qreal contrastFactor = (factor + 100.0) / 100.0;

        for (int y = 0; y < modifiedImage.height(); y++) {
            for (int x = 0; x < modifiedImage.width(); x++) {
                QRgb pixel = modifiedImage.pixel(x, y);

                modifiedImage.setPixel(x, y, qRgb(qBound(0, static_cast<int>((qRed(pixel) - 128) * contrastFactor + 128), 255),
                                                  qBound(0, static_cast<int>((qGreen(pixel) - 128) * contrastFactor + 128), 255),
                                                  qBound(0, static_cast<int>((qBlue(pixel) - 128) * contrastFactor + 128), 255)));
            }
        }
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::brightness(int delta)
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        for (int y = 0; y < modifiedImage.height(); y++) {
            for (int x = 0; x < modifiedImage.width(); x++) {
                QRgb pixel = modifiedImage.pixel(x, y);

                modifiedImage.setPixel(x, y, qRgb(qBound(0, qRed(pixel) + delta, 255),
                                                  qBound(0, qGreen(pixel) + delta, 255),
                                                  qBound(0, qBlue(pixel) + delta, 255)));
            }
        }
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::colorInversion()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        for (int y = 0; y < modifiedImage.height(); y++) {
            for (int x = 0; x < modifiedImage.width(); x++) {
                QRgb pixel = modifiedImage.pixel(x, y);
                modifiedImage.setPixel(x, y, qRgb(255 - qRed(pixel), 255 - qGreen(pixel), 255 - qBlue(pixel)));
            }
        }
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::mozaicImage(int cellSize)
{
    if (!modifiedImage.isNull() && cellSize > 0) {
        imageVersions.push(modifiedImage);

        for (int y = 0; y < modifiedImage.height(); y += cellSize) {
            for (int x = 0; x < modifiedImage.width(); x += cellSize) {
                int totalRed = 0;
                int totalGreen = 0;
                int totalBlue = 0;
                int pixelsCount = 0;

                for (int dy = 0; dy < cellSize; dy++) {
                    for (int dx = 0; dx < cellSize; dx++) {
                        int newX = x + dx;
                        int newY = y + dy;

                        if (newX < modifiedImage.width() && newY < modifiedImage.height()) {
                            QRgb pixel = modifiedImage.pixel(newX, newY);
                            totalRed += qRed(pixel);
                            totalGreen += qGreen(pixel);
                            totalBlue += qBlue(pixel);
                            pixelsCount++;
                        }
                    }
                }
                int averageRed = totalRed / pixelsCount;
                int averageGreen = totalGreen / pixelsCount;
                int averageBlue = totalBlue / pixelsCount;

                for (int i = 0; i < cellSize; i++) {
                    for (int j = 0; j < cellSize; j++) {
                        int newX = x + i;
                        int newY = y + j;

                        if (newX < modifiedImage.width() && newY < modifiedImage.height()) {
                            modifiedImage.setPixel(newX, newY, qRgb(averageRed, averageGreen, averageBlue));
                        }
                    }
                }
            }
        }
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::embossImage()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        QImage newImage = modifiedImage;
        std::vector <std::vector<int>>convolutionMatrix;
        convolutionMatrix.resize(3, std::vector<int>(3));
        convolutionMatrix[0][0] = -2, convolutionMatrix[0][1] = -1, convolutionMatrix[1][0] = -1, convolutionMatrix[1][1] = 1, convolutionMatrix[1][2] = 1, convolutionMatrix[2][1] = 1, convolutionMatrix[2][2] = 2;

        for (size_t y = 1; y < modifiedImage.height() - convolutionMatrix.size() / 2; y++) {
            for (size_t x = 1; x < modifiedImage.width() - convolutionMatrix.size() / 2; x++) {
                int gray = 0;

                for (size_t t = 0; t < convolutionMatrix.size(); t++) {
                    for (size_t p = 0; p < convolutionMatrix.size(); p++) {
                        QColor pixelColor = QColor(modifiedImage.pixel(x + p - 1, y + t - 1));
                        int intensity = pixelColor.red() * 0.299 + pixelColor.green() * 0.587 + pixelColor.blue() * 0.114;
                        gray += intensity * convolutionMatrix[t][p];
                    }
                }
                newImage.setPixelColor(x, y, QColor(qBound(0, gray + 128, 255), qBound(0, gray + 128, 255), qBound(0, gray + 128, 255)));
            }
        }
        modifiedImage = newImage;
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::denoiseImage()
{
    if (!modifiedImage.isNull()) {
        imageVersions.push(modifiedImage);

        cv::Mat matImage(originalImage.height(), originalImage.width(), CV_BGR2RGB, (cv::Scalar*)originalImage.scanLine(0));
        cv::Mat result = matImage;
        cv::fastNlMeansDenoisingColored(matImage, result, 20, 20, 7, 21);
        QImage newImage(result.data, result.cols, result.rows, QImage::Format_RGB32);

        modifiedImage = newImage;
        originalImage = modifiedImage;
        isImageModified = true;

        updateDisplay();
    }
}

void MainWindow::updateDisplay()
{
    int maxDisplayWidth = imageLabel->width() * 4 / 5;
    int maxDisplayHeight = imageLabel->height() * 4 / 5;

    if (isScaling) {
        int displayWidth = std::min(maxDisplayWidth, static_cast<int>(originalImage.width() * scaleFactor));
        int displayHeight = std::min(maxDisplayHeight, static_cast<int>(originalImage.height() * scaleFactor));

        int displayX = (imageLabel->width() - displayWidth) / 2;
        int displayY = (imageLabel->height() - displayHeight) / 2;

        displayPixmap = QPixmap(imageLabel->size());
        displayPixmap.fill(Qt::white);

        QPainter painter(&displayPixmap);
        painter.drawImage(displayX, displayY, originalImage.scaled(displayWidth, displayHeight));

        modifiedImage = originalImage.scaled(displayWidth, displayHeight);
        isImageModified = true;
    } else if (isResizing && (horizontalStretchAction->isChecked() || verticalStretchAction->isChecked())) {
        int displayWidth = modifiedImage.width();
        int displayHeight = modifiedImage.height();

        if (horizontalStretchAction->isChecked()) {
            int newWidth = displayWidth + (imageLabel->mapFromGlobal(QCursor::pos()).x() - lastMousePos.x());

            newWidth = std::min(maxDisplayWidth, std::max(newWidth, 1));
            modifiedImage = originalImage.scaled(newWidth, displayHeight);
        } else if (verticalStretchAction->isChecked()) {
            int newHeight = displayHeight + (imageLabel->mapFromGlobal(QCursor::pos()).y() - lastMousePos.y());

            newHeight = std::min(maxDisplayHeight, std::max(newHeight, 1));
            modifiedImage = originalImage.scaled(displayWidth, newHeight);
        }

        int displayX = (imageLabel->width() - modifiedImage.width()) / 2;
        int displayY = (imageLabel->height() - modifiedImage.height()) / 2;

        displayPixmap = QPixmap(imageLabel->size());
        displayPixmap.fill(Qt::white);

        QPainter painter(&displayPixmap);

        painter.drawImage(displayX, displayY, modifiedImage);
    } else {
        int displayX = (imageLabel->width() - (isImageModified ? modifiedImage : originalImage).width()) / 2;
        int displayY = (imageLabel->height() - (isImageModified ? modifiedImage : originalImage).height()) / 2;

        displayPixmap = QPixmap(imageLabel->size());
        displayPixmap.fill(Qt::white);

        QPainter painter(&displayPixmap);
        painter.drawImage(displayX, displayY, isImageModified ? modifiedImage : originalImage);
    }
    imageLabel->setPixmap(displayPixmap);

    toolbar->actions()[3]->setEnabled(!originalImage.isNull());
    toolbar->actions()[4]->setEnabled(!originalImage.isNull());
    toolbar->actions()[5]->setEnabled(!originalImage.isNull());
    toolbar->actions()[6]->setEnabled(!originalImage.isNull());
    toolbar->actions()[7]->setEnabled(!imageVersions.isEmpty());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!originalImage.isNull() && event->button() == Qt::RightButton) {
        QMenu contextMenu(this);

        contextMenu.addAction(tr("&Mirror Reflection"), this, &MainWindow::mirrorImage);
        contextMenu.addAction(tr("&Blur"), this, [this]() { blurPro(5); });
        contextMenu.addAction(tr("&Grayscale"), this, &MainWindow::grayscale);
        contextMenu.addAction(tr("&Sepia Tone"), this, &MainWindow::sepiaTone);
        contextMenu.addAction(tr("&Emboss"), this, &MainWindow::embossImage);
        contextMenu.addAction(tr("&Contrast+"), this, [this]() { сontrast(30); });
        contextMenu.addAction(tr("&Contrast-"), this, [this]() { сontrast(-30); });
        contextMenu.addAction(tr("&Brightness+"), this, [this]() { brightness(10); });
        contextMenu.addAction(tr("&Brightness-"), this, [this]() { brightness(-10); });
        contextMenu.addAction(tr("&Invert Colors"), this, &MainWindow::colorInversion);
        contextMenu.addAction(tr("&Mozaic"), this, [this]() { mozaicImage(15); });
        contextMenu.addAction(tr("&Sharpen"), this, &MainWindow::sharpenImage);
        contextMenu.exec(event->globalPos());
    } else if (isScaling && imageLabel->rect().contains(event->pos())) {
        lastMousePos = event->pos();
        isMoving = true;
        imageLabel->setCursor(Qt::ClosedHandCursor);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isMoving) {
        QPoint delta = event->pos() - lastMousePos;
        scaleFactor -= delta.y() * 0.0008;
        if (scaleFactor < 0.1) {
            scaleFactor = 0.1;
        }

        updateDisplay();
    }

    if (isResizing) {
        QPoint delta = event->pos() - lastMousePos;
        if (horizontalStretchAction->isChecked()) {
            int newWidth = modifiedImage.width() + delta.x() * 0.000001;
            newWidth = std::max(newWidth, 1);
            newWidth = std::min(newWidth, centralWidget()->width() * 4 / 5);
            modifiedImage = originalImage.scaled(newWidth, modifiedImage.height());
        } else if (verticalStretchAction->isChecked()) {
            int newHeight = modifiedImage.height() + delta.y() * 0.000001;
            newHeight = std::max(newHeight, 1);
            newHeight = std::min(newHeight, centralWidget()->height() * 4 / 5);
            modifiedImage = originalImage.scaled(modifiedImage.width(), newHeight);
        }

        updateDisplay();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (isMoving) {
        isMoving = false;
        imageLabel->setCursor(Qt::OpenHandCursor);
        if (isResizing || isScaling) {
            isImageModified = true;

            updateDisplay();
        }
    }
}

void MainWindow::slotShortcutCtrlO()
{
    openImage();
}

void MainWindow::slotShortcutCtrlS()
{
    if (!originalImage.isNull()) {
        saveImage();
    }
}

void MainWindow::slotShortcutCtrlZ()
{
    undo();
}

void MainWindow::slotShortcutCtrlL()
{
    openLastImagesList();
}

void MainWindow::slotShortcutCtrlP()
{
    openCamWindow();
}
