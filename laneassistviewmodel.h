#pragma once

#include <QObject>

class LaneAssistViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(int side READ side WRITE setSide NOTIFY sideChanged)

public:
    explicit LaneAssistViewModel(QObject *parent = nullptr);

    int side() const;
    void setSide(int newSide);

signals:
    void sideChanged();
public slots:
    void updateSide(int side);


private:
    int m_side;
};
