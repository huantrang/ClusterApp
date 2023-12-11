import QtQuick

Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("Hello World")
    ClusterScreen
    {
        id: normalMode;
        anchors.fill: parent;
    }
}
