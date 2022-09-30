#include <QGuiApplication>
#include <QQmlApplicationEngine>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    #include "SBarcodeFilter.h"
#else
    #include "SBarcodeScanner.h"
#endif

#include "interface.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    qmlRegisterType<SBarcodeFilter>("com.scythestudio.scodes", 1, 0, "SBarcodeScanner");
    engine.load(QUrl(QStringLiteral("qrc:/qml/Qt5ScannerPage.qml")));
#else
    qmlRegisterType<SBarcodeScanner>("com.scythestudio.scodes", 1, 0, "SBarcodeScanner");
#endif
    QScopedPointer<Interface> interfaceInstancePtr (new Interface());

    QQmlApplicationEngine engine;

    qmlRegisterSingletonInstance("com.trungnd.interface", 1, 0, "BackendInterface", interfaceInstancePtr.get());
    // TODO: Doi url
    engine.load(QUrl(QStringLiteral("qrc:/qml/Qt6ScannerPage.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}