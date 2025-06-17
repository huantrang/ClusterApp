#include "commonmodel.h"

CommonModel::CommonModel(QObject *parent)
    : BaseModel(parent)
{
}

uint64_t CommonModel::odoValue() const
{
    return m_odoValue;
}

void CommonModel::setOdoValue(uint64_t newOdoValue)
{
    if (m_odoValue != newOdoValue) {
        m_odoValue = newOdoValue;
        emit odoValueChanged(m_odoValue);
    }
}

float CommonModel::fuelValue() const
{
    return m_fuelValue;
}

void CommonModel::setFuelValue(float newFuelValue)
{
    if (!qFuzzyCompare(m_fuelValue, newFuelValue)) {
        m_fuelValue = newFuelValue;
        emit fuelValueChanged(m_fuelValue);
    }
}

float CommonModel::batteryValue() const
{
    return m_batteryValue;
}

void CommonModel::setBatteryValue(float newBatteryValue)
{
    if (!qFuzzyCompare(m_batteryValue, newBatteryValue)) {
        m_batteryValue = newBatteryValue;
        emit batteryValueChanged(m_batteryValue);
    }
}

void CommonModel::updateData(const QJsonObject &data)
{
    if (data.contains("odoValue") && data["odoValue"].isDouble())
        setOdoValue(static_cast<uint64_t>(data["odoValue"].toDouble()));

    if (data.contains("fuelValue") && data["fuelValue"].isDouble())
        setFuelValue(static_cast<float>(data["fuelValue"].toDouble()));

    if (data.contains("batteryValue") && data["batteryValue"].isDouble())
        setBatteryValue(static_cast<float>(data["batteryValue"].toDouble()));
}
