#pragma once

#include <QObject>

constexpr quint16 TELLTALE_LEFT_ARROW      = 1 << 0;
constexpr quint16 TELLTALE_DOORS           = 1 << 1;
constexpr quint16 TELLTALE_WHEEL           = 1 << 2;
constexpr quint16 TELLTALE_SEAT_BELT       = 1 << 3;
constexpr quint16 TELLTALE_BRAKE_SYSTEM    = 1 << 4;
constexpr quint16 TELLTALE_PARKING_LIGHTS  = 1 << 5;
constexpr quint16 TELLTALE_MALFUNCTION     = 1 << 6;
constexpr quint16 TELLTALE_HIGH_BEAMS      = 1 << 7;
constexpr quint16 TELLTALE_OIL             = 1 << 8;
constexpr quint16 TELLTALE_RIGHT_ARROW     = 1 << 9;

class TelltaleViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool leftArrowActive READ leftArrowActive WRITE setLeftArrowActive NOTIFY leftArrowActiveChanged)
    Q_PROPERTY(bool doorsActive READ doorsActive WRITE setDoorsActive NOTIFY doorsActiveChanged)
    Q_PROPERTY(bool wheelActive READ wheelActive WRITE setWheelActive NOTIFY wheelActiveChanged)
    Q_PROPERTY(bool seatBeltActive READ seatBeltActive WRITE setSeatBeltActive NOTIFY seatBeltActiveChanged)
    Q_PROPERTY(bool brakeSystemActive READ brakeSystemActive WRITE setBrakeSystemActive NOTIFY brakeSystemActiveChanged)
    Q_PROPERTY(bool parkingLightsActive READ parkingLightsActive WRITE setParkingLightsActive NOTIFY parkingLightsActiveChanged)
    Q_PROPERTY(bool malfunctionActive READ malfunctionActive WRITE setMalfunctionActive NOTIFY malfunctionActiveChanged)
    Q_PROPERTY(bool highBeamsActive READ highBeamsActive WRITE setHighBeamsActive NOTIFY highBeamsActiveChanged)
    Q_PROPERTY(bool oilActive READ oilActive WRITE setOilActive NOTIFY oilActiveChanged)
    Q_PROPERTY(bool rightArrowActive READ rightArrowActive WRITE setRightArrowActive NOTIFY rightArrowActiveChanged)

public:
    explicit TelltaleViewModel(QObject *parent = nullptr);

    bool leftArrowActive() const;
    void setLeftArrowActive(bool value);

    bool doorsActive() const;
    void setDoorsActive(bool value);

    bool wheelActive() const;
    void setWheelActive(bool value);

    bool seatBeltActive() const;
    void setSeatBeltActive(bool value);

    bool brakeSystemActive() const;
    void setBrakeSystemActive(bool value);

    bool parkingLightsActive() const;
    void setParkingLightsActive(bool value);

    bool malfunctionActive() const;
    void setMalfunctionActive(bool value);

    bool highBeamsActive() const;
    void setHighBeamsActive(bool value);

    bool oilActive() const;
    void setOilActive(bool value);

    bool rightArrowActive() const;
    void setRightArrowActive(bool value);

signals:
    void leftArrowActiveChanged();
    void doorsActiveChanged();
    void wheelActiveChanged();
    void seatBeltActiveChanged();
    void brakeSystemActiveChanged();
    void parkingLightsActiveChanged();
    void malfunctionActiveChanged();
    void highBeamsActiveChanged();
    void oilActiveChanged();
    void rightArrowActiveChanged();

public slots:
    void updateTelltaleFlags(quint16 flags);


private:
    bool m_leftArrowActive{false};
    bool m_doorsActive{false};
    bool m_wheelActive{false};
    bool m_seatBeltActive{false};
    bool m_brakeSystemActive{false};
    bool m_parkingLightsActive{false};
    bool m_malfunctionActive{false};
    bool m_highBeamsActive{false};
    bool m_oilActive{false};
    bool m_rightArrowActive{false};
};
