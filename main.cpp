#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QVariant>
#include "CallbackFunction.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    auto rootObject = engine.rootObjects().at(0);
    QMetaObject::invokeMethod(rootObject, "testCallback", Q_ARG(QVariant, QVariant::fromValue(new CallbackFunction)));

    return app.exec();
}
