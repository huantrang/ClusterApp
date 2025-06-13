#ifndef GEARSHIFTMODEL_H
#define GEARSHIFTMODEL_H

#include "basemodel.h"

#include <QString>

class GearShiftModel : public BaseModel
{
    Q_OBJECT
public:
    explicit GearShiftModel(QObject *parent = nullptr);

    uint8_t gearShiftNumber() const;
    void setGearShiftNumber(const uint8_t newGearShiftNumber);

    double rpmValue() const;
    void setRPMValue(double newRPMValue);

    double maxRPMValue() const;
    void setMaxRPMValue(double newMaxRPMValue);

signals:
    void gearShiftNumberChanged(uint8_t gearShiftNumber);
    void rpmValueChanged(double rpmValue);
    void maxRPMValueChanged(double maxRPMValue);

private:
    uint8_t m_gearShiftNumber;
    double m_rpmValue{0};
    double m_maxRPMValue{10};



    // BaseModel interface
public:
    void updateData(const QJsonObject &data);
};

#endif // GEARSHIFTMODEL_H
