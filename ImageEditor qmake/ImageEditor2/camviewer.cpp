#include "camviewer.h"

camViewer::camViewer(QWidget *centralWidget) : QGraphicsView(centralWidget) {}

camViewer::camViewer(QGraphicsScene *scene, QWidget* parent) : QGraphicsView(scene, parent) {}

camViewer::~camViewer() {}

void camViewer::setImage(QImage frame)
{
    currentImage = frame;
    this->scene()->update();
}

void camViewer::paintEvent(QPaintEvent *event)
{
    QPainter painter(viewport());
    painter.drawImage(QRect(0, 0, viewport()->width(), viewport()->height()), currentImage, QRect(0, 0, currentImage.width(), currentImage.height()));
    QGraphicsView::paintEvent(event);
}
