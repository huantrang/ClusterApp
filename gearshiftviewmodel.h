#ifndef GEARSHIFTVIEWMODEL_H
#define GEARSHIFTVIEWMODEL_H

#include <QObject>

class GearShiftViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString GearShiftNumber READ GearShiftNumber WRITE setGearShiftNumber NOTIFY GearShiftNumberChanged FINAL)
    Q_PROPERTY(double RPMValue READ RPMValue WRITE setRPMValue NOTIFY RPMValueChanged FINAL)
    Q_PROPERTY(double MaxRPMValue READ MaxRPMValue WRITE setMaxRPMValue NOTIFY MaxRPMValueChanged FINAL)
public:
    explicit GearShiftViewModel(QObject *parent = nullptr);

    QString GearShiftNumber() const;
    void setGearShiftNumber(const QString &newGearShiftNumber);

    double RPMValue() const;
    void setRPMValue(double newRPMValue);

    double MaxRPMValue() const;
    void setMaxRPMValue(double newMaxRPMValue);

signals:
    void GearShiftNumberChanged();
    void RPMValueChanged();

    void MaxRPMValueChanged();

private:
    QString m_GearShiftNumber{"P"};
    double m_RPMValue{0};
    double m_MaxRPMValue{10};
};

#endif // GEARSHIFTVIEWMODEL_H
