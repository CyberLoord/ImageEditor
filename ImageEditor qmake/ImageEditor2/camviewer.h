#ifndef CAMVIEWER_H
#define CAMVIEWER_H

#include <QGraphicsScene>
#include <QGraphicsView>

class camViewer : public QGraphicsView
{
public:
    camViewer(QWidget *centralWidget);
    camViewer(QGraphicsScene *scene, QWidget *parent = nullptr);
    ~camViewer();

    void setImage(QImage frame);

private:
    QImage currentImage;

protected:
    void paintEvent(QPaintEvent *paintEventInfo);
};

#endif // CAMVIEWER_H
