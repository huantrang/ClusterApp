#include "model/commonmodel.h"
#include "socket/TcpReceiver.h"
#include "TelltaleViewModel.h"
#include "commonviewmodel.h"
#include "gearshiftviewmodel.h"
#include "laneassistviewmodel.h"
#include "naviviewmodel.h"
#include "speedviewmodel.h"
#include "tempviewmodel.h"

#include "model/gearshiftmodel.h"
#include "model/laneassistmodel.h"
#include "model/speedmodel.h"
#include "model/navimodel.h"
#include "model/telltalemodel.h"
#include "model/tempmodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include <QRandomGenerator>
#include <QThread>

void startTcpReceiver(quint16 port, BaseModel *model) {
    TcpReceiver *receiver = new TcpReceiver();
    QThread *receiverThread = new QThread();

    receiver->moveToThread(receiverThread);

    QObject::connect(receiver, &TcpReceiver::messageReceived, [=](QJsonObject data) {
        model->updateData(data);
    });

    QObject::connect(receiverThread, &QThread::started, [=]() {
        receiver->startServer(port);
    });

    QObject::connect(receiverThread, &QThread::finished, receiver, &QObject::deleteLater);

    receiverThread->start();
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Main.qml"_qs);

    std::shared_ptr<SpeedViewModel> speedVM = std::make_shared<SpeedViewModel>();
    std::shared_ptr<GearShiftViewModel> gearShiftVM = std::make_shared<GearShiftViewModel>();
    std::shared_ptr<TempViewModel> tempVM = std::make_shared<TempViewModel>();
    std::shared_ptr<NaviViewModel> naviVM = std::make_shared<NaviViewModel>();
    std::shared_ptr<LaneAssistViewModel> laneVM = std::make_shared<LaneAssistViewModel>();
    std::shared_ptr<TelltaleViewModel> telltaleVM = std::make_shared<TelltaleViewModel>();
    std::shared_ptr<CommonViewModel> commonVM = std::make_shared<CommonViewModel>();

    std::shared_ptr<GearShiftModel> gearShiftModel = std::make_shared<GearShiftModel>();
    std::shared_ptr<LaneAssistModel> laneModel = std::make_shared<LaneAssistModel>();
    std::shared_ptr<NaviModel> naviModel = std::make_shared<NaviModel>();
    std::shared_ptr<SpeedModel> speedModel = std::make_shared<SpeedModel>();
    std::shared_ptr<TelltaleModel> telltaleModel = std::make_shared<TelltaleModel>();
    std::shared_ptr<TempModel> tempModel = std::make_shared<TempModel>();
    std::shared_ptr<CommonModel> commonModel = std::make_shared<CommonModel>();

    QQmlContext* rootContext = engine.rootContext();
    rootContext->setContextProperty("SpeedViewModel", speedVM.get());
    rootContext->setContextProperty("GearShiftViewModel", gearShiftVM.get());
    rootContext->setContextProperty("TempViewModel", tempVM.get());
    rootContext->setContextProperty("NaviViewModel", naviVM.get());
    rootContext->setContextProperty("LaneAssistViewModel", laneVM.get());
    rootContext->setContextProperty("TelltaleViewModel", telltaleVM.get());
    rootContext->setContextProperty("CommonViewModel", commonVM.get());

    // Speed
    QObject::connect(speedModel.get(), &SpeedModel::speedChanged,
                     speedVM.get(), &SpeedViewModel::updateSpeed);
    QObject::connect(speedModel.get(), &SpeedModel::unitChanged,
                     speedVM.get(), &SpeedViewModel::updateUnit);
    QObject::connect(speedModel.get(), &SpeedModel::maxSpeedChanged,
                     speedVM.get(), &SpeedViewModel::updateMaxSpeed);

    // Gear Shift
    QObject::connect(gearShiftModel.get(), &GearShiftModel::gearShiftNumberChanged,
                     gearShiftVM.get(), &GearShiftViewModel::updateGearShiftNumber);
    QObject::connect(gearShiftModel.get(), &GearShiftModel::rpmValueChanged,
                     gearShiftVM.get(), &GearShiftViewModel::updateRPMValue);
    QObject::connect(gearShiftModel.get(), &GearShiftModel::maxRPMValueChanged,
                     gearShiftVM.get(), &GearShiftViewModel::updateMaxRPMValue);

    // Temperature
    QObject::connect(tempModel.get(), &TempModel::tempChanged,
                     tempVM.get(), &TempViewModel::updateTemp);
    QObject::connect(tempModel.get(), &TempModel::maxTempChanged,
                     tempVM.get(), &TempViewModel::updateMaxTemp);
    QObject::connect(tempModel.get(), &TempModel::tempUnitChanged,
                     tempVM.get(), &TempViewModel::updateTempUnit);

    // Navigation
    QObject::connect(naviModel.get(), &NaviModel::arrowTypeChanged,
                     naviVM.get(), &NaviViewModel::updateArrowType);
    QObject::connect(naviModel.get(), &NaviModel::filteredDistanceToNextManoeuverChanged,
                     naviVM.get(), &NaviViewModel::updateFilteredDistanceToNextManoeuver);
    QObject::connect(naviModel.get(), &NaviModel::streetChanged,
                     naviVM.get(), &NaviViewModel::updateStreet);
    QObject::connect(naviModel.get(), &NaviModel::limitedSpeedChanged,
                     naviVM.get(), &NaviViewModel::updateLimitedSpeed);

    // Lane Assist
    QObject::connect(laneModel.get(), &LaneAssistModel::sideChanged,
                     laneVM.get(), &LaneAssistViewModel::updateSide);

    // Telltale
    QObject::connect(telltaleModel.get(), &TelltaleModel::telltaleFlagsChanged,
                     telltaleVM.get(), &TelltaleViewModel::updateTelltaleFlags);

    // Common Data
    QObject::connect(commonModel.get(), &CommonModel::odoValueChanged,
                     commonVM.get(), &CommonViewModel::updateOdoValue);
    QObject::connect(commonModel.get(), &CommonModel::fuelValueChanged,
                     commonVM.get(), &CommonViewModel::updateFuelValue);
    QObject::connect(commonModel.get(), &CommonModel::batteryValueChanged,
                     commonVM.get(), &CommonViewModel::updateBatteryValue);

    //start socket
    startTcpReceiver(12345, gearShiftModel.get());
    startTcpReceiver(12346, laneModel.get());
    startTcpReceiver(12347, naviModel.get());
    startTcpReceiver(12348, speedModel.get());
    startTcpReceiver(12349, telltaleModel.get());
    startTcpReceiver(12350, tempModel.get());
    startTcpReceiver(12351, commonModel.get());
    //end socket




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
