#include "laneassistmodel.h"

LaneAssistModel::LaneAssistModel(QObject *parent)
    : BaseModel(parent), m_side(0)
{}

int LaneAssistModel::side() const
{
    return m_side;
}

void LaneAssistModel::setSide(int newSide)
{
    if (m_side != newSide) {
        m_side = newSide;
        emit sideChanged(m_side);
    }
}

void LaneAssistModel::updateData(const QJsonObject &data) {
    if (data.contains("side") && data.value("side").isDouble()) {
        int newSide = data.value("side").toInt();
        setSide(newSide);
    }
}
