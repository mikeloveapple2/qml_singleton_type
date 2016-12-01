#include "foo.h"
#include "manager.h"

#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Second, define the singleton type provider function (callback).
static QObject *manager_provider(QQmlEngine *engine, QJSEngine *scriptEngine);

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // Must be new in heap
    Manager* manager = new Manager;
    qDebug("manager : %x\n", &manager);

    qmlRegisterSingletonType<Manager>("Ho0", 1, 0, "Manager", manager_provider);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Foo foo;
    Q_UNUSED(foo);

    return app.exec();
}

static QObject *manager_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

   Manager* instance = Manager::getInstance();
   return instance;
}
