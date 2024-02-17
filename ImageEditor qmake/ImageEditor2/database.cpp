#include "database.h"

dataBase::dataBase(QObject *parent) : QObject(parent) {}

dataBase::~dataBase() {}

void dataBase::connectToDB()
{
    if (!QFile("../images.db").exists()) {
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool dataBase::restoreDataBase()
{
    if (this->openDataBase()) {
        return (this->createTable()) ? true : false;
    } else {
        qDebug() << "Failed to restore database";
        return false;
    }
    return false;
}

bool dataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("ImagesDatabase");
    db.setDatabaseName("../images.db");
    if (db.open()) {
        return true;
    } else {
        return false;
    }
}

void dataBase::closeDataBase()
{
    db.close();
}

bool dataBase::createTable()
{
    QSqlQuery query;

    if (!query.exec("CREATE TABLE ImagesTable ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "FileName VARCHAR(255) NOT NULL,"
                    "Image BLOB NOT NULL"
                    " )"
    )) {
        qDebug() << "DataBase: error of create ImagesTable";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }

    return false;
}

bool dataBase::insertIntoTable(const QVariantList &data)
{
    QSqlQuery query;

    query.prepare("INSERT INTO ImagesTable ( FileName, "
                  "Image ) "
                  "VALUES (:Name, :Pic)");
    query.bindValue(":Name", data[0].toString());
    query.bindValue(":Pic", data[1].toByteArray());

    if (!query.exec()) {
        qDebug() << "Faild insert into ImagesTable";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }

    return false;
}

bool dataBase::insertIntoTable(const QString &filename, const QByteArray &image)
{
    QVariantList data;

    data.append(filename);
    data.append(image);

    if (insertIntoTable(data)) {
        return true;
    } else {
        return false;
    }

    return false;
}

bool dataBase::removeImage(const int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ImagesTable WHERE id= :ID ;");
    query.bindValue(":ID", id);
    if(!query.exec()) {
        qDebug() << "Faild delete from ImagesTable";
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}
