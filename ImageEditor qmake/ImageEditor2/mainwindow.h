#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "camerawindow.h"
#include "imageslist.h"

#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QCursor>
#include <QStack>
#include <QShortcut>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QLabel *imageLabel;
    QToolBar *toolbar;
    QAction *scaleAction;
    QAction *horizontalStretchAction;
    QAction *verticalStretchAction;
    qreal scaleFactor;
    bool isScaling;
    bool isMoving;
    bool isResizing;
    bool isImageModified;
    imagesList *lastImagesList;
    cameraWindow *camWindow;
    QImage originalImage;
    QImage modifiedImage;
    QStack<QImage> imageVersions;
    QPixmap displayPixmap;
    QPoint lastMousePos;
    QShortcut *ctrlO;
    QShortcut *ctrlS;
    QShortcut *ctrlZ;
    QShortcut *ctrlL;
    QShortcut *ctrlP;

    void insertImage(QImage image);
    void openImage();
    void saveImage();
    void scaleImage(qreal factor);
    void stretchImageHorizontal();
    void stretchImageVertical();
    void undo();
    void mirrorImage();
    void blurPro(int radius);
    void grayscale();
    void sepiaTone();
    void sharpenImage();
    void сontrast(int factor);
    void brightness(int delta);
    void colorInversion();
    void mozaicImage(int cellSize);
    void embossImage();
    void denoiseImage();
    void updateDisplay();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
    void slotOpenImage(QPixmap pixmapImage);

private slots:
    void openLastImagesList();
    void openCamWindow();
    void slotShortcutCtrlO();
    void slotShortcutCtrlS();
    void slotShortcutCtrlZ();
    void slotShortcutCtrlL();
    void slotShortcutCtrlP();
};

#endif // MAINWINDOW_H
