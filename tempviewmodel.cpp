#include "tempviewmodel.h"

TempViewModel::TempViewModel(QObject *parent)
    : QObject{parent}
{}

double TempViewModel::Temp() const
{
    return m_Temp;
}

void TempViewModel::setTemp(double newTemp)
{
    if (qFuzzyCompare(m_Temp, newTemp) || newTemp > m_MaxTemp || newTemp < 0)
        return;
    m_Temp = newTemp;
    emit TempChanged();
}

double TempViewModel::MaxTemp() const
{
    return m_MaxTemp;
}

void TempViewModel::setMaxTemp(double newMaxTemp)
{
    if (qFuzzyCompare(m_MaxTemp, newMaxTemp))
        return;
    m_MaxTemp = newMaxTemp;
    emit MaxTempChanged();
}

QString TempViewModel::TempUnit() const
{
    return m_TempUnit;
}

void TempViewModel::setTempUnit(const QString &newTempUnit)
{
    if (m_TempUnit == newTempUnit)
        return;
    m_TempUnit = newTempUnit;
    emit TempUnitChanged();
}

void TempViewModel::updateTemp(double temp)
{
    setTemp(temp);
}

void TempViewModel::updateMaxTemp(double maxTemp)
{
    setMaxTemp(maxTemp);
}

void TempViewModel::updateTempUnit(const QString &unit)
{
    setTempUnit(unit);
}
