#ifndef TEMPVIEWMODEL_H
#define TEMPVIEWMODEL_H

#include <QObject>

class TempViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double Temp READ Temp WRITE setTemp NOTIFY TempChanged FINAL)
    Q_PROPERTY(double MaxTemp READ MaxTemp WRITE setMaxTemp NOTIFY MaxTempChanged FINAL)
    Q_PROPERTY(QString TempUnit READ TempUnit WRITE setTempUnit NOTIFY TempUnitChanged FINAL)
public:
    explicit TempViewModel(QObject *parent = nullptr);

    double Temp() const;
    void setTemp(double newTemp);

    double MaxTemp() const;
    void setMaxTemp(double newMaxTemp);

    QString TempUnit() const;
    void setTempUnit(const QString &newTempUnit);

signals:
    void TempChanged();
    void MaxTempChanged();
    void TempUnitChanged();

public slots:
    void updateTemp(double temp);
    void updateMaxTemp(double maxTemp);
    void updateTempUnit(const QString &unit);


private:
    double m_Temp{0};
    double m_MaxTemp{180};
    QString m_TempUnit{"°C"};
};

#endif // TEMPVIEWMODEL_H
