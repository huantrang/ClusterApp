#include "gearshiftmodel.h"
#include <QtMath>

GearShiftModel::GearShiftModel(QObject *parent)
    : BaseModel(parent), m_gearShiftNumber(0), m_rpmValue(0.0), m_maxRPMValue(8000.0)
{}

uint8_t GearShiftModel::gearShiftNumber() const
{
    return m_gearShiftNumber;
}

void GearShiftModel::setGearShiftNumber(const uint8_t newGearShiftNumber)
{
    if (m_gearShiftNumber != newGearShiftNumber) {
        m_gearShiftNumber = newGearShiftNumber;
        emit gearShiftNumberChanged(m_gearShiftNumber);
    }
}

double GearShiftModel::rpmValue() const
{
    return m_rpmValue;
}

void GearShiftModel::setRPMValue(double newRPMValue)
{
    if (!qFuzzyCompare(m_rpmValue, newRPMValue)) {
        m_rpmValue = newRPMValue;
        emit rpmValueChanged(m_rpmValue);
    }
}

double GearShiftModel::maxRPMValue() const
{
    return m_maxRPMValue;
}

void GearShiftModel::setMaxRPMValue(double newMaxRPMValue)
{
    if (!qFuzzyCompare(m_maxRPMValue, newMaxRPMValue)) {
        m_maxRPMValue = newMaxRPMValue;
        emit maxRPMValueChanged(m_maxRPMValue);
    }
}

void GearShiftModel::updateData(const QJsonObject &data) {
    if (data.contains("gearShiftNumber") && data.value("gearShiftNumber").isDouble()) {
        uint8_t newGearShiftNumber = static_cast<uint8_t>(data.value("gearShiftNumber").toInt());
        setGearShiftNumber(newGearShiftNumber);
    }

    if (data.contains("rpmValue") && data.value("rpmValue").isDouble()) {
        double newRPMValue = data.value("rpmValue").toDouble();
        setRPMValue(newRPMValue);
    }
}

