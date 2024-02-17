#include "camerawindow.h"
#include "ui_camerawindow.h"

cameraWindow::cameraWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::cameraWindow),
        filterStatus(5)
{
    ui->setupUi(this);
    setWindowTitle("Take A Photo");

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,  SLOT(updateView()));
    timer->start(30);

    ui->cam->setScene(&scene);
}

cameraWindow::~cameraWindow()
{
    delete ui;
    if (video.isOpened()) {
         video.release();
    }
}

void cameraWindow::closeWindow()
{
    this->close();
}

void cameraWindow::on_recordButton_clicked()
{
    if (video.isOpened()) {
         video.release();
         ui->recordButton->setText("Start");
    }
    else {
        video.open(false);
        ui->recordButton->setText("Stop");
    }
}

void cameraWindow::updateView()
{
    if (!video.isOpened()) {
        return;
    }
    while(true) {
        video >> frame;
        if (!frame.empty()) {
            break;
        }
    }
    if (frame.empty()) {
        return;
    }
    cv::Mat newFrame = frame;
    cv::Mat grayFrame = frame;

    if (filterStatus == 1) {
        cv::stylization(frame, newFrame, 20, 0.07);
    } else if (filterStatus == 2) {
        cv::pencilSketch(frame, grayFrame, newFrame, 60, 0.1, 0.03);
    } else if (filterStatus == 3) {
        cv::detailEnhance(frame, newFrame, 10, 0.15);
    } else if (filterStatus == 4) {
        cv::edgePreservingFilter(frame, newFrame, 1, 60, 0.4);
    }

    ui->cam->setImage(QImage((const unsigned char*)(newFrame.data), newFrame.cols, newFrame.rows, QImage::Format_RGB888).rgbSwapped());
}

void cameraWindow::on_closeWindowButton_clicked()
{
    closeWindow();
}

void cameraWindow::on_openImageButton_clicked()
{
    closeWindow();
    emit signalOpenImage(QPixmap::fromImage(QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped()));
}

void cameraWindow::on_applyFilterButton_clicked()
{
    QMenu *contextMenu = new QMenu(this);

    contextMenu->addAction(tr("&Painting"), this, [this]() { filterStatus = 1; });
    contextMenu->addAction(tr("&Cartoon"), this, [this]() { filterStatus = 2; });
    contextMenu->addAction(tr("&Extra Detail"), this, [this]() { filterStatus = 3; });
    contextMenu->addAction(tr("&Make Up"), this, [this]() { filterStatus = 4; });
    contextMenu->addAction(tr("&Reset"), this, [this]() { filterStatus = 0; });
    ui->applyFilterButton->setMenu(contextMenu);
}
