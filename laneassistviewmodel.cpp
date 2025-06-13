#include "laneassistviewmodel.h"

LaneAssistViewModel::LaneAssistViewModel(QObject *parent)
    : QObject(parent), m_side{0} {}

int LaneAssistViewModel::side() const {
    return m_side;
}

void LaneAssistViewModel::setSide(int newSide) {
    if (m_side != newSide) {
        m_side = newSide;
        emit sideChanged();
    }
}
void LaneAssistViewModel::updateSide(int side)
{
    setSide(side);
}
