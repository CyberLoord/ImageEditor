#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

class dataBase : public QObject
{
    Q_OBJECT
public:
    explicit dataBase(QObject *parent = nullptr);
    ~dataBase();

     void connectToDB();

private:
    QSqlDatabase db;

    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();

public slots:
    bool insertIntoTable(const QVariantList &data);
    bool insertIntoTable(const QString &filename, const QByteArray &image);
    bool removeImage(const int id);

};

#endif // DATABASE_H
