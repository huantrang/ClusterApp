#ifndef TEMPMODEL_H
#define TEMPMODEL_H

#include "basemodel.h"
#include <QString>

class TempModel : public BaseModel
{
    Q_OBJECT
public:
    explicit TempModel(QObject *parent = nullptr);

    double temp() const;
    void setTemp(double newTemp);

    double maxTemp() const;
    void setMaxTemp(double newMaxTemp);

    QString tempUnit() const;
    void setTempUnit(const QString &newTempUnit);

signals:
    void tempChanged(double temp);
    void maxTempChanged(double maxTemp);
    void tempUnitChanged(QString tempUnit);

private:
    double m_Temp = 0.0;
    double m_MaxTemp = 180.0;
    QString m_TempUnit = "C";


    // BaseModel interface
public:
    void updateData(const QJsonObject &data);
};

#endif // TEMPMODEL_H
