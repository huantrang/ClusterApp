#ifndef COMMONMODEL_H
#define COMMONMODEL_H

#include "basemodel.h"

class CommonModel : public BaseModel
{
    Q_OBJECT
public:
    explicit CommonModel(QObject *parent = nullptr);

    uint64_t odoValue() const;
    void setOdoValue(uint64_t newOdoValue);

    float fuelValue() const;
    void setFuelValue(float newFuelValue);

    float batteryValue() const;
    void setBatteryValue(float newBatteryValue);

signals:
    void odoValueChanged(uint64_t odoValue);
    void fuelValueChanged(float fuelValue);
    void batteryValueChanged(float batteryValue);

    // BaseModel interface
public:
    void updateData(const QJsonObject &data) override;

private:
    uint64_t m_odoValue = 0;
    float m_fuelValue = 0.0f;
    float m_batteryValue = 0.0f;
};

#endif // COMMONMODEL_H
