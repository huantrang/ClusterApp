#include "speedmodel.h"

SpeedModel::SpeedModel(QObject *parent)
    : BaseModel(parent)
{}

double SpeedModel::speed() const {
    return m_speed;
}

void SpeedModel::setSpeed(double newSpeed) {
    // if (qFuzzyCompare(m_speed, newSpeed) || newSpeed > m_maxSpeed || newSpeed < 0)
    //     return;
    m_speed = newSpeed;
    emit speedChanged(m_speed);
}

QString SpeedModel::unit() const {
    return m_unit;
}

void SpeedModel::setUnit(const QString &newUnit) {
    if (m_unit == newUnit)
        return;
    m_unit = newUnit;
    emit unitChanged(m_unit);
}

uint64_t SpeedModel::maxSpeed() const {
    return m_maxSpeed;
}

void SpeedModel::setMaxSpeed(uint64_t newMaxSpeed) {
    if (m_maxSpeed == newMaxSpeed)
        return;
    m_maxSpeed = newMaxSpeed;
    emit maxSpeedChanged(m_maxSpeed);
}

void SpeedModel::updateData(const QJsonObject &data) {
    if (data.contains("speed") && data.value("speed").isDouble()) {
        setSpeed(data.value("speed").toDouble());
    }
}
