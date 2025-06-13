#ifndef SPEEDMODEL_H
#define SPEEDMODEL_H

#include "basemodel.h"

#include <QString>

class SpeedModel : public BaseModel
{
    Q_OBJECT
public:
    explicit SpeedModel(QObject *parent = nullptr);

    double speed() const;
    void setSpeed(double newSpeed);

    QString unit() const;
    void setUnit(const QString &newUnit);

    uint64_t maxSpeed() const;
    void setMaxSpeed(uint64_t newMaxSpeed);

signals:
    void speedChanged(double speed);
    void unitChanged(QString unit);
    void maxSpeedChanged(uint64_t maxSpeed);

private:
    double m_speed = 0.0;
    QString m_unit;
    uint64_t m_maxSpeed = 240;

    // BaseModel interface
public:
    void updateData(const QJsonObject &data);
};

#endif // SPEEDMODEL_H
