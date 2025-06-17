#include "commonviewmodel.h"

CommonViewModel::CommonViewModel(QObject *parent)
    : QObject(parent)
{
}

// --- ODO ---
uint64_t CommonViewModel::odoValue() const
{
    return m_odoValue;
}

void CommonViewModel::setOdoValue(uint64_t newOdoValue)
{
    if (m_odoValue != newOdoValue) {
        m_odoValue = newOdoValue;
        emit odoValueChanged();
    }
}

void CommonViewModel::updateOdoValue(uint64_t odo)
{
    setOdoValue(odo);
}

// --- Fuel ---
float CommonViewModel::fuelValue() const
{
    return m_fuelValue;
}

void CommonViewModel::setFuelValue(float newFuelValue)
{
    if (!qFuzzyCompare(m_fuelValue, newFuelValue)) {
        m_fuelValue = newFuelValue;
        emit fuelValueChanged();
    }
}

void CommonViewModel::updateFuelValue(float fuel)
{
    setFuelValue(fuel);
}

// --- Battery ---
float CommonViewModel::batteryValue() const
{
    return m_batteryValue;
}

void CommonViewModel::setBatteryValue(float newBatteryValue)
{
    if (!qFuzzyCompare(m_batteryValue, newBatteryValue)) {
        m_batteryValue = newBatteryValue;
        emit batteryValueChanged();
    }
}

void CommonViewModel::updateBatteryValue(float battery)
{
    setBatteryValue(battery);
}
