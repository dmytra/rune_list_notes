#include "database.h"
#include <QStandardPaths>


DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    if(!QFile(DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);

    //https://stackoverflow.com/questions/52337354/how-to-write-files-to-an-android-device-using-qt
    QString path = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    db.setDatabaseName(path+"/"+DATABASE_NAME);

    qDebug() << "openDataBase";

    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}



bool DataBase::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_DATE      " DATE            NOT NULL,"
                    TABLE_TIME      " TIME            NOT NULL,"
                    TABLE_NAMES     " VARCHAR(255)    NOT NULL,"
                    TABLE_MESSAGE   " TEXT            NOT NULL"
                    " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::inserIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE " ( " TABLE_DATE ", "
                  TABLE_TIME ", "
                  TABLE_NAMES ", "
                  TABLE_MESSAGE " ) "
                  "VALUES (:Date, :Time, :Runanames, :Message )");
    query.bindValue(":Date",        data[0].toDate());
    query.bindValue(":Time",        data[1].toTime());
    query.bindValue(":Runanames",   data[2].toString());
    query.bindValue(":Message",     data[3].toString());

    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}


QString DataBase::selectFromTable(QString &namess )
{
    QString selNamessDB = "SELECT Message FROM TableExample WHERE Runanames = '" + namess + "' ";
    QSqlQuery query(selNamessDB);
    QString message = "";

    while (query.next()) {
        message = query.value(0).toString();
        //qDebug() << "1111######" << message;
    }
    if(!query.exec()){
        qDebug() << "error select from " << TABLE;
        qDebug() << query.lastError().text();
        return "";
    } else {
        return message;
    }
    return "";
}









