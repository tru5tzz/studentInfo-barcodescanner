#ifndef __BACKEND__
#define __BACKEND__

#include <QtGlobal>

class Backend : public QObject {
    Q_OBJECT

public:
    Backend(QObject *parent = nullptr);
    ~Backend() override;

public slots:

    void searchName(QString id);

private:
    QString studentName;

    QSqlDatabase db;
signals:
    void nameFound(QString name);

}

#endif