#include "interface.h"
#include "Backend.h"

#include <QObject>
#include <QQmlEngine>
#include <QtGlobal>

Interface::Interface(QObject *parent)
    : QObject(parent)
    , backend(nullptr)
{
    backend = new Backend();

    connect(this, &Interface::barcodeScanned, backend, &Backend::searchName);
    connect(backend, &Backend::nameFound, this, &Interface::triggerNameFound);

}

Interface::~Interface() {
    backend::~Backend();
}

void Interface::triggerNameFound(QString name) {
    if (name == m_nameTag) {
        return;
    }

    m_nameTag = name;
}

void Interface::barcodeValue(QString result) {
    emit Interface::barcodeScanned(result);
}