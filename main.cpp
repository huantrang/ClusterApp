#include "gearshiftviewmodel.h"
#include "speedviewmodel.h"
#include "tempviewmodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Main.qml"_qs);

    std::shared_ptr<SpeedViewModel> speedVM = std::make_shared<SpeedViewModel>();
    std::shared_ptr<GearShiftViewModel> gearShiftVM = std::make_shared<GearShiftViewModel>();
    std::shared_ptr<TempViewModel> tempVM = std::make_shared<TempViewModel>();

    QQmlContext* rootContext = engine.rootContext();
    rootContext->setContextProperty("SpeedViewModel", speedVM.get());
    rootContext->setContextProperty("GearShiftViewModel", gearShiftVM.get());
    rootContext->setContextProperty("TempViewModel", tempVM.get());

    QTimer timer;

    int interval = 10;
    double speed = 0;
    double temp = 0;
    double rpm = 0;
    speedVM->setSpeed(speed);
    tempVM->setTemp(temp);
    QObject::connect(&timer, &QTimer::timeout, [&]() {
            speed+=0.1;
            speedVM->setSpeed(speed);
            temp+=0.1;
            tempVM->setTemp(temp);
            rpm+= 0.01;
            gearShiftVM->setRPMValue(rpm);
    });

    timer.start(interval);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
