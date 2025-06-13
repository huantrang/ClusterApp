#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>

class TcpReceiver : public QObject {
    Q_OBJECT
public:
    explicit TcpReceiver(QObject *parent = nullptr);

public slots:
    void startServer(quint16 port);

signals:
    void messageReceived(QJsonObject data);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer *server;
    QTcpSocket *clientSocket = nullptr;
};
