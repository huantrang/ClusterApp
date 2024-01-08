#ifndef SPEEDVIEWMODEL_H
#define SPEEDVIEWMODEL_H

#include "clusterstruct.h"
#include <QObject>

class SpeedViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double Speed READ Speed WRITE setSpeed NOTIFY SpeedChanged)
    Q_PROPERTY(uint64_t LimitedSpeed READ LimitedSpeed WRITE setLimitedSpeed NOTIFY LimitedSpeedChanged)
    Q_PROPERTY(QString Unit READ Unit WRITE setUnit NOTIFY UnitChanged)

public:
    explicit SpeedViewModel(QObject *parent = nullptr);

    double Speed() const;
    void setSpeed(double newSpeed);
    uint64_t LimitedSpeed() const;
    void setLimitedSpeed(uint64_t newLimitedSpeed);

    QString Unit() const;
    void setUnit(const QString &newUnit);

signals:
    void SpeedChanged();
    void LimitedSpeedChanged();
    void UnitChanged();

public slots:
    void onSpeedDataModelChanged(SpeedData speedData);

private:
    double m_Speed;
    uint64_t m_LimitedSpeed;
    QString m_Unit;
};

#endif // SPEEDVIEWMODEL_H
