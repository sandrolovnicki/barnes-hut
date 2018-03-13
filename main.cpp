#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "update.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    UpdateBH updatebh;
    QQuickView view;
    view.engine()->rootContext()->setContextProperty("updatebh", &updatebh);
    view.setSource(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
