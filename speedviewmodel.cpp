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

void SpeedViewModel::updateSpeed(double speed)
{
    setSpeed(speed);
}

void SpeedViewModel::updateUnit(const QString &unit)
{
    setUnit(unit);
}

void SpeedViewModel::updateMaxSpeed(uint64_t maxSpeed)
{
    setMaxSpeed(maxSpeed);
}
