#ifndef __QT_INTERFACE__
#define __QT_INTERFACE__

#include <QObject>
#include <QQmlEngine>
#include <QtGlobal>
#include "Backend.h"

class Interface : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QString nameTag READ nameTag WRITE setNameTag)

public:
    explicit Interface(QObject *parent = nullptr);
    ~Interface() override;

    QString nameTag() const{
        return m_nameTag;
    }

    void setNameTag(QString name) {
        if (name == m_nameTag) {
            return;
        }

        m_nameTag = name;
    }

public slots:

    /*
     * Connect to frontend
     * Frontend use this method
     */
    
    void barcodeValue(QString result);

    /*
     * Connect to backend
     * Will be call automatically when the backend emits the signal.
     */
    void triggerNameFound(Qstring name);
    /*
     * 
     */
private:
    Backend *backend;

    QString m_nameTag;

signals:

    /*
     * Emitted when the frontend scanned a valid barcode
     * Connect this signal to a backend method.
     */
    void barcodeScanned(QString *result);

    /*
     * Emitted when the backend found the student name
     * Use this to transfer the name to frontend
     * Connect to Scanner
     * CURRENTLY NOT IN USE
     */
    void nameFound(QString *studentName);

}

#endif