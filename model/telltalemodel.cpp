#include "telltalemodel.h"

TelltaleModel::TelltaleModel(QObject *parent)
    : BaseModel(parent)
{
}

void TelltaleModel::setFlag(quint16 flag)
{
    m_flags |= flag;
    emit telltaleFlagsChanged(m_flags);
}

void TelltaleModel::clearFlag(quint16 flag)
{
    m_flags &= ~flag;
    emit telltaleFlagsChanged(m_flags);
}

void TelltaleModel::setFlags(quint16 flags)
{
    m_flags = flags;
    emit telltaleFlagsChanged(m_flags);
}

void TelltaleModel::resetFlags()
{
    m_flags = 0;
    emit telltaleFlagsChanged(m_flags);
}

void TelltaleModel::updateData(const QJsonObject &data) {
    if (data.contains("flags") && data.value("flags").isDouble()) {
        setFlags(static_cast<quint16>(data.value("flags").toInt()));
    }
}
