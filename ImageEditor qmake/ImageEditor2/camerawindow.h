#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include "camviewer.h"

#include <QWidget>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/photo.hpp>
#include <QTimer>
#include <QDebug>
#include <QMenu>
#include <QMouseEvent>

namespace Ui {
class cameraWindow;
}

class cameraWindow : public QWidget
{
    Q_OBJECT

public:
    explicit cameraWindow(QWidget *parent = nullptr);
    ~cameraWindow();

private:
    Ui::cameraWindow* ui;
    int filterStatus;
    QGraphicsScene scene;
    cv::VideoCapture video;
    cv::Mat frame;
    bool isCameraOn;

    void closeWindow();

signals:
    void signalOpenImage(QPixmap image);

private slots:
    void on_recordButton_clicked();
    void updateView(void);
    void on_applyFilterButton_clicked();
    void on_closeWindowButton_clicked();
    void on_openImageButton_clicked();
};

#endif // CAMERAWINDOW_H
