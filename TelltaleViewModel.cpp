#include "TelltaleViewModel.h"

TelltaleViewModel::TelltaleViewModel(QObject *parent) : QObject(parent) {}

bool TelltaleViewModel::leftArrowActive() const { return m_leftArrowActive; }
void TelltaleViewModel::setLeftArrowActive(bool value) {
    if (m_leftArrowActive != value) {
        m_leftArrowActive = value;
        emit leftArrowActiveChanged();
    }
}

bool TelltaleViewModel::doorsActive() const { return m_doorsActive; }
void TelltaleViewModel::setDoorsActive(bool value) {
    if (m_doorsActive != value) {
        m_doorsActive = value;
        emit doorsActiveChanged();
    }
}

bool TelltaleViewModel::wheelActive() const { return m_wheelActive; }
void TelltaleViewModel::setWheelActive(bool value) {
    if (m_wheelActive != value) {
        m_wheelActive = value;
        emit wheelActiveChanged();
    }
}

bool TelltaleViewModel::seatBeltActive() const { return m_seatBeltActive; }
void TelltaleViewModel::setSeatBeltActive(bool value) {
    if (m_seatBeltActive != value) {
        m_seatBeltActive = value;
        emit seatBeltActiveChanged();
    }
}

bool TelltaleViewModel::brakeSystemActive() const { return m_brakeSystemActive; }
void TelltaleViewModel::setBrakeSystemActive(bool value) {
    if (m_brakeSystemActive != value) {
        m_brakeSystemActive = value;
        emit brakeSystemActiveChanged();
    }
}

bool TelltaleViewModel::parkingLightsActive() const { return m_parkingLightsActive; }
void TelltaleViewModel::setParkingLightsActive(bool value) {
    if (m_parkingLightsActive != value) {
        m_parkingLightsActive = value;
        emit parkingLightsActiveChanged();
    }
}

bool TelltaleViewModel::malfunctionActive() const { return m_malfunctionActive; }
void TelltaleViewModel::setMalfunctionActive(bool value) {
    if (m_malfunctionActive != value) {
        m_malfunctionActive = value;
        emit malfunctionActiveChanged();
    }
}

bool TelltaleViewModel::highBeamsActive() const { return m_highBeamsActive; }
void TelltaleViewModel::setHighBeamsActive(bool value) {
    if (m_highBeamsActive != value) {
        m_highBeamsActive = value;
        emit highBeamsActiveChanged();
    }
}

bool TelltaleViewModel::oilActive() const { return m_oilActive; }
void TelltaleViewModel::setOilActive(bool value) {
    if (m_oilActive != value) {
        m_oilActive = value;
        emit oilActiveChanged();
    }
}

bool TelltaleViewModel::rightArrowActive() const { return m_rightArrowActive; }
void TelltaleViewModel::setRightArrowActive(bool value) {
    if (m_rightArrowActive != value) {
        m_rightArrowActive = value;
        emit rightArrowActiveChanged();
    }
}

void TelltaleViewModel::updateTelltaleFlags(quint16 flags)
{
    setLeftArrowActive(flags & TELLTALE_LEFT_ARROW);
    setDoorsActive(flags & TELLTALE_DOORS);
    setWheelActive(flags & TELLTALE_WHEEL);
    setSeatBeltActive(flags & TELLTALE_SEAT_BELT);
    setBrakeSystemActive(flags & TELLTALE_BRAKE_SYSTEM);
    setParkingLightsActive(flags & TELLTALE_PARKING_LIGHTS);
    setMalfunctionActive(flags & TELLTALE_MALFUNCTION);
    setHighBeamsActive(flags & TELLTALE_HIGH_BEAMS);
    setOilActive(flags & TELLTALE_OIL);
    setRightArrowActive(flags & TELLTALE_RIGHT_ARROW);
}

