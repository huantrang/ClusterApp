#include "naviviewmodel.h"

NaviViewModel::NaviViewModel(QObject *parent)
    : QObject(parent), m_arrowType(ArrowNone)
{
}

int NaviViewModel::arrowType() const {
    return m_arrowType;
}

void NaviViewModel::setArrowType(int type) {
    if (m_arrowType != type) {
        m_arrowType = type;
        emit arrowTypeChanged();
    }
}

QString NaviViewModel::getArrowSource() const {
    switch (m_arrowType) {
        case ArrowForward: return "qrc:/images/arrows/arrow-straight.png";
        case ArrowRight45: return "qrc:/images/arrows/arrow-right-45.png";
        case ArrowRight90: return "qrc:/images/arrows/arrow-right-90.png";
        case ArrowRightRound: return "qrc:/images/arrows/arrow-right-round.png";
        case ArrowLeft45: return "qrc:/images/arrows/arrow-left-45.png";
        case ArrowLeft90: return "qrc:/images/arrows/arrow-left-90.png";
        case ArrowLeftRound: return "qrc:/images/arrows/arrow-left-round.png";
        default: return "";
    }
}

QString NaviViewModel::filteredDistanceToNextManoeuver() const {
    return m_filteredDistanceToNextManoeuver;
}

void NaviViewModel::setFilteredDistanceToNextManoeuver(const QString &value) {
    if (m_filteredDistanceToNextManoeuver != value) {
        m_filteredDistanceToNextManoeuver = value;
        emit filteredDistanceToNextManoeuverChanged();
    }
}

QString NaviViewModel::instruction() const {
    return m_instruction;
}

void NaviViewModel::setInstruction(const QString &value) {
    if (m_instruction != value) {
        m_instruction = value;
        emit instructionChanged();
    }
}

QString NaviViewModel::street() const {
    return m_street;
}

void NaviViewModel::setStreet(const QString &value) {
    if (m_street != value) {
        m_street = value;
        emit streetChanged();
    }
}

void NaviViewModel::updateArrowType(int type)
{
    setArrowType(type);
    switch (type) {
    case ArrowForward: setInstruction("Keep going straight"); break;
    case ArrowRight45:
    case ArrowRight90:
    case ArrowRightRound: setInstruction("Turn right"); break;
    case ArrowLeft45:
    case ArrowLeft90:
    case ArrowLeftRound: setInstruction("Turn left"); break;
    default: break;
    }
}

void NaviViewModel::updateFilteredDistanceToNextManoeuver(const uint64_t distance)
{
    setFilteredDistanceToNextManoeuver(QString::number(distance));
}

void NaviViewModel::updateStreet(const QString &street)
{
    setStreet(street);
}

uint64_t NaviViewModel::LimitedSpeed() const
{
    return m_LimitedSpeed;
}

void NaviViewModel::setLimitedSpeed(uint64_t newLimitedSpeed)
{
    if (m_LimitedSpeed == newLimitedSpeed)
        return;
    m_LimitedSpeed = newLimitedSpeed;
    emit LimitedSpeedChanged();
}

void NaviViewModel::updateLimitedSpeed(uint64_t limitedSpeed)
{
    setLimitedSpeed(limitedSpeed);
}
