#ifndef IMAGESLIST_H
#define IMAGESLIST_H

#include "database.h"

#include <QSqlTableModel>
#include <QModelIndex>
#include <QSqlRecord>
#include <QWidget>
#include <QBuffer>
#include <QMessageBox>

namespace Ui {
class imagesList;
}

class imagesList : public QWidget
{
    Q_OBJECT

public:
    explicit imagesList(QWidget *parent = nullptr);
    void saveImageToDB(QPixmap inPixmap);

    ~imagesList();

private:
    dataBase *db;
    Ui::imagesList *ui;
    QSqlTableModel *model;
    QPixmap dedicatedImage;

    void setupModel(const QString &tablename, const QStringList &headers);
    void createUI();
    void closeWindow();

signals:
    void mainWindow();
    void signalOpenImage(QPixmap image);

private slots:
    void slotCurrentImage(QModelIndex index);
    void on_backButton_clicked();
    void on_openImageButton_clicked();
    void on_deleteImageButton_clicked();

};

#endif // imagesList_H
