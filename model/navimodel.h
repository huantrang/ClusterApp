#ifndef NAVIMODEL_H
#define NAVIMODEL_H

#include "basemodel.h"

#include <QString>

class NaviModel : public BaseModel
{
    Q_OBJECT
public:
    explicit NaviModel(QObject *parent = nullptr);

    int arrowType() const;
    void setArrowType(int type);

    uint64_t filteredDistanceToNextManoeuver() const;
    void setFilteredDistanceToNextManoeuver(const uint64_t value);

    QString street() const;
    void setStreet(const QString &value);

    uint64_t limitedSpeed() const;
    void setLimitedSpeed(uint64_t newLimitedSpeed);


signals:
    void arrowTypeChanged(int arrowType);
    void filteredDistanceToNextManoeuverChanged(uint64_t filteredDistanceToNextManoeuver);
    void streetChanged(QString street);
    void limitedSpeedChanged(uint64_t limitedSpeed);

private:
    int m_arrowType;
    uint64_t m_filteredDistanceToNextManoeuver;
    QString m_street;
    uint64_t m_limitedSpeed = 0;

    // BaseModel interface
public:
    void updateData(const QJsonObject &data);
};

#endif // NAVIMODEL_H
