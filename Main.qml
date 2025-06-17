import QtQuick

Window {
    id:root
    width: 800
    height: 480
    visible: true
    color: "#00091a"

    // Biến điều khiển hiển thị màn hình chính
    property bool splashFinished: false

    SplashScreen {
        id: splashScreen
        anchors.fill: parent
        visible: !root.splashFinished
        onSplashDone: root.splashFinished = true
    }

    ClusterScreen
    {
        id:clusterScreen ;
        anchors.fill: parent;
        visible: root.splashFinished
    }
}
