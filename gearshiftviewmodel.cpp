#include "gearshiftviewmodel.h"

GearShiftViewModel::GearShiftViewModel(QObject *parent)
    : QObject{parent}
{}

QString GearShiftViewModel::GearShiftNumber() const
{
    return m_GearShiftNumber;
}

void GearShiftViewModel::setGearShiftNumber(const QString &newGearShiftNumber)
{
    if (m_GearShiftNumber == newGearShiftNumber)
        return;
    m_GearShiftNumber = newGearShiftNumber;
    emit GearShiftNumberChanged();
}

double GearShiftViewModel::RPMValue() const
{
    return m_RPMValue;
}

void GearShiftViewModel::setRPMValue(double newRPMValue)
{
    if (qFuzzyCompare(m_RPMValue, newRPMValue) || newRPMValue > m_MaxRPMValue || newRPMValue < 0)
        return;
    m_RPMValue = newRPMValue;
    emit RPMValueChanged();
}

double GearShiftViewModel::MaxRPMValue() const
{
    return m_MaxRPMValue;
}

void GearShiftViewModel::setMaxRPMValue(double newMaxRPMValue)
{
    if (qFuzzyCompare(m_MaxRPMValue, newMaxRPMValue))
        return;
    m_MaxRPMValue = newMaxRPMValue;
    emit MaxRPMValueChanged();
}
