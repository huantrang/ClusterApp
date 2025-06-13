#include "navimodel.h"

NaviModel::NaviModel(QObject *parent)
    : BaseModel(parent), m_arrowType(0)
{}

int NaviModel::arrowType() const {
    return m_arrowType;
}

void NaviModel::setArrowType(int type) {
    if (m_arrowType != type) {
        m_arrowType = type;
        emit arrowTypeChanged(m_arrowType);
    }
}

uint64_t NaviModel::filteredDistanceToNextManoeuver() const {
    return m_filteredDistanceToNextManoeuver;
}

void NaviModel::setFilteredDistanceToNextManoeuver(const uint64_t value) {
    if (m_filteredDistanceToNextManoeuver != value) {
        m_filteredDistanceToNextManoeuver = value;
        emit filteredDistanceToNextManoeuverChanged(m_filteredDistanceToNextManoeuver);
    }
}

QString NaviModel::street() const {
    return m_street;
}

void NaviModel::setStreet(const QString &value) {
    if (m_street != value) {
        m_street = value;
        emit streetChanged(m_street);
    }
}

void NaviModel::updateData(const QJsonObject &data) {
    if (data.contains("arrowType") && data.value("arrowType").isDouble()) {
        setArrowType(data.value("arrowType").toInt());
    }

    if (data.contains("filteredDistanceToNextManoeuver") && data.value("filteredDistanceToNextManoeuver").isDouble()) {
        setFilteredDistanceToNextManoeuver(static_cast<uint64_t>(data.value("filteredDistanceToNextManoeuver").toDouble()));
    }

    if (data.contains("street") && data.value("street").isString()) {
        setStreet(data.value("street").toString());
    }

    if (data.contains("limitedSpeed") && data.value("limitedSpeed").isDouble()) {
        setLimitedSpeed(static_cast<uint64_t>(data.value("limitedSpeed").toDouble()));
    }
}

uint64_t NaviModel::limitedSpeed() const {
    return m_limitedSpeed;
}

void NaviModel::setLimitedSpeed(uint64_t newLimitedSpeed) {
    if (m_limitedSpeed == newLimitedSpeed)
        return;
    m_limitedSpeed = newLimitedSpeed;
    emit limitedSpeedChanged(m_limitedSpeed);
}

