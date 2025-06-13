#include "gearshiftviewmodel.h"
#include <QDebug>

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

void GearShiftViewModel::updateGearShiftNumber(const uint8_t gearShift)
{
    QString gear;

    switch (gearShift)
    {
    case 0: gear = "P"; break;  // Park
    case 1: gear = "R"; break; // Reverse
    case 2: gear = "N"; break; // Neutral
    case 3: gear = "D"; break;  // Drive
    case 4: gear = "S"; break;  // Sport
    case 5: gear = "L"; break;  // Low
    case 6: gear = "1"; break;  // Manual gear 1
    case 7: gear = "2"; break;
    case 8: gear = "3"; break;
    case 9: gear = "4"; break;
    case 10: gear = "5"; break;
    case 11: gear = "6"; break;
    default: gear = "Unknown"; break;
    }

    setGearShiftNumber(gear);
}

void GearShiftViewModel::updateRPMValue(double rpm)
{
    setRPMValue(rpm);
}

void GearShiftViewModel::updateMaxRPMValue(double maxRpm)
{
    setMaxRPMValue(maxRpm);
}
