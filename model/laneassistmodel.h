#ifndef LANEASSISTMODEL_H
#define LANEASSISTMODEL_H

#include "basemodel.h"

#include <QObject>

class LaneAssistModel : public BaseModel
{
    Q_OBJECT
public:
    explicit LaneAssistModel(QObject *parent = nullptr);

    int side() const;
    void setSide(int newSide);

signals:
    void sideChanged(int side);

private:
    int m_side;

    // BaseModel interface
public:
    void updateData(const QJsonObject &data);
};

#endif // LANEASSISTMODEL_H
