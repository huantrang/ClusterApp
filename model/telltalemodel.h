#pragma once

#include "basemodel.h"


class TelltaleModel : public BaseModel
{
    Q_OBJECT

public:
    explicit TelltaleModel(QObject *parent = nullptr);

    void setFlag(quint16 flag);
    void clearFlag(quint16 flag);
    void setFlags(quint16 flags);
    void resetFlags();

signals:
    void telltaleFlagsChanged(quint16 flags);

private:
    quint16 m_flags{0};

    // BaseModel interface
public:
    void updateData(const QJsonObject &data);
};
