#ifndef COMMONVIEWMODEL_H
#define COMMONVIEWMODEL_H

#include <QObject>

class CommonViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint64_t odoValue READ odoValue WRITE setOdoValue NOTIFY odoValueChanged)
    Q_PROPERTY(float fuelValue READ fuelValue WRITE setFuelValue NOTIFY fuelValueChanged)
    Q_PROPERTY(float batteryValue READ batteryValue WRITE setBatteryValue NOTIFY batteryValueChanged)

public:
    explicit CommonViewModel(QObject *parent = nullptr);

    uint64_t odoValue() const;
    void setOdoValue(uint64_t newOdoValue);

    float fuelValue() const;
    void setFuelValue(float newFuelValue);

    float batteryValue() const;
    void setBatteryValue(float newBatteryValue);

signals:
    void odoValueChanged();
    void fuelValueChanged();
    void batteryValueChanged();

public slots:
    void updateOdoValue(uint64_t odo);
    void updateFuelValue(float fuel);
    void updateBatteryValue(float battery);

private:
    uint64_t m_odoValue{0};
    float m_fuelValue{0.0f};
    float m_batteryValue{0.0f};
};

#endif // COMMONVIEWMODEL_H
