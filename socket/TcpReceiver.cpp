#include "TcpReceiver.h"

TcpReceiver::TcpReceiver(QObject *parent) : QObject(parent), server(new QTcpServer(this)) {
    connect(server, &QTcpServer::newConnection, this, &TcpReceiver::onNewConnection);
}

void TcpReceiver::startServer(quint16 port) {
    if (!server->listen(QHostAddress::Any, port)) {
        qWarning() << "Server start failed:" << server->errorString();
    } else {
        qDebug() << "Server listening on port" << port;
    }
}

void TcpReceiver::onNewConnection() {
    clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &TcpReceiver::onReadyRead);
}

void TcpReceiver::onReadyRead() {
    QByteArray data = clientSocket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isNull()) {
        QJsonObject obj = doc.object();
        emit messageReceived(obj);
    }
}
