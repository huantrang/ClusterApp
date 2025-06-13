#pragma once

#include <QObject>
#include <QString>

class NaviViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(int arrowType READ arrowType WRITE setArrowType NOTIFY arrowTypeChanged)
    Q_PROPERTY(QString arrowSource READ getArrowSource NOTIFY arrowTypeChanged)
    Q_PROPERTY(QString filteredDistanceToNextManoeuver READ filteredDistanceToNextManoeuver WRITE setFilteredDistanceToNextManoeuver NOTIFY filteredDistanceToNextManoeuverChanged)
    Q_PROPERTY(QString instruction READ instruction WRITE setInstruction NOTIFY instructionChanged)
    Q_PROPERTY(QString street READ street WRITE setStreet NOTIFY streetChanged)
    Q_PROPERTY(uint64_t LimitedSpeed READ LimitedSpeed WRITE setLimitedSpeed NOTIFY LimitedSpeedChanged)

public:
    enum ArrowType {
        ArrowNone = 0,
        ArrowForward,
        ArrowRight45,
        ArrowRight90,
        ArrowRightRound,
        ArrowLeft45,
        ArrowLeft90,
        ArrowLeftRound,
    };
    Q_ENUM(ArrowType)

    explicit NaviViewModel(QObject *parent = nullptr);

    int arrowType() const;
    void setArrowType(int type);

    Q_INVOKABLE QString getArrowSource() const;

    QString filteredDistanceToNextManoeuver() const;
    void setFilteredDistanceToNextManoeuver(const QString &value);

    QString instruction() const;
    void setInstruction(const QString &value);

    QString street() const;
    void setStreet(const QString &value);

    uint64_t LimitedSpeed() const;
    void setLimitedSpeed(uint64_t newLimitedSpeed);


signals:
    void arrowTypeChanged();
    void filteredDistanceToNextManoeuverChanged();
    void instructionChanged();
    void streetChanged();
    void LimitedSpeedChanged();

public slots:
    void updateArrowType(int type);
    void updateFilteredDistanceToNextManoeuver(const uint64_t distance);
    void updateStreet(const QString &street);
    void updateLimitedSpeed(uint64_t limitedSpeed);

private:
    int m_arrowType;
    QString m_filteredDistanceToNextManoeuver;
    QString m_instruction;
    QString m_street;
    uint64_t m_LimitedSpeed{0};
};
