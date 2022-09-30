#include "Backend.h"

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QObject>

QString queryCommand = "SELECT name FROM studentInfo WHERE id = (:id)";

Backend::Backend(QObject *parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("$HOME/student-id.db");

    if(db.open()) {
        qDebug() << "Database open successfully!!";
    }
    else {
        qDebug() << "Database open failed!!!" << db.lastError();
    }
}

Backend::~Backend() {
    db.close();
    db.removeDatabase();
}

void Backend::searchName(QString id) {

    QSqlQuery query;
    query.prepare(queryCommand);
    query.bindValue(":id", id);
    int success = query.exec();

    if (!success) {
        qDebug() << "Query failed" << query.lastError();
    }
    else {
        if(query.first()) {
            qDebug() << "Got the name: " << query.value(0).toString();
            emit nameFound(query.value(0).toString());
        }
        else {
            qDebug() << "No valid name found";
        }
    }

}