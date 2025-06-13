#include "tempmodel.h"
#include <QtGlobal>

TempModel::TempModel(QObject *parent)
    : BaseModel(parent)
{}

double TempModel::temp() const
{
    return m_Temp;
}

void TempModel::setTemp(double newTemp)
{
    if (qFuzzyCompare(m_Temp, newTemp) || newTemp > m_MaxTemp || newTemp < 0)
        return;
    m_Temp = newTemp;
    emit tempChanged(m_Temp);
}

double TempModel::maxTemp() const
{
    return m_MaxTemp;
}

void TempModel::setMaxTemp(double newMaxTemp)
{
    if (qFuzzyCompare(m_MaxTemp, newMaxTemp))
        return;
    m_MaxTemp = newMaxTemp;
    emit maxTempChanged(m_MaxTemp);
}

QString TempModel::tempUnit() const
{
    return m_TempUnit;
}

void TempModel::setTempUnit(const QString &newTempUnit)
{
    if (m_TempUnit == newTempUnit)
        return;
    m_TempUnit = newTempUnit;
    emit tempUnitChanged(m_TempUnit);
}

void TempModel::updateData(const QJsonObject &data) {
    if (data.contains("temp") && data.value("temp").isDouble()) {
        setTemp(data.value("temp").toDouble());
    }

}
