#include "speedviewmodel.h"

SpeedViewModel::SpeedViewModel(QObject *parent)
    : QObject{parent}
{
}

double SpeedViewModel::Speed() const
{
    return m_Speed;
}

void SpeedViewModel::setSpeed(double newSpeed)
{
    if (qFuzzyCompare(m_Speed,newSpeed) || newSpeed > m_MaxSpeed || newSpeed < 0)
        return;
    m_Speed = newSpeed;
    emit SpeedChanged();
}

uint64_t SpeedViewModel::LimitedSpeed() const
{
    return m_LimitedSpeed;
}

void SpeedViewModel::setLimitedSpeed(uint64_t newLimitedSpeed)
{
    if (m_LimitedSpeed == newLimitedSpeed)
        return;
    m_LimitedSpeed = newLimitedSpeed;
    emit LimitedSpeedChanged();
}

QString SpeedViewModel::Unit() const
{
    return m_Unit;
}

void SpeedViewModel::setUnit(const QString &newUnit)
{
    if (m_Unit == newUnit)
        return;
    m_Unit = newUnit;
    emit UnitChanged();
}

void SpeedViewModel::onSpeedDataModelChanged(SpeedData speedData)
{
    setSpeed(speedData.m_Speed);
    setLimitedSpeed(speedData.m_LimitedSpeed);
    setUnit(QString::fromStdString(speedData.m_Unit));
}

uint64_t SpeedViewModel::MaxSpeed() const
{
    return m_MaxSpeed;
}

void SpeedViewModel::setMaxSpeed(uint64_t newMaxSpeed)
{
    if (m_MaxSpeed == newMaxSpeed)
        return;
    m_MaxSpeed = newMaxSpeed;
    emit MaxSpeedChanged();
}
