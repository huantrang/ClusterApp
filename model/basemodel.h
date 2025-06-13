#ifndef BASEMODEL_H
#define BASEMODEL_H
#include <QObject>
#include <QJsonObject>
class BaseModel : public QObject {
    Q_OBJECT
public:
    explicit BaseModel(QObject *parent = nullptr) : QObject(parent) {}
    virtual void updateData(const QJsonObject &data) = 0;
};

#endif // BASEMODEL_H
