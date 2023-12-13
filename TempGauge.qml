import QtQuick

BaseGauge {
    id: root;
    needleOffsetY: -13

    gaugeSource: sportGauge
    needleSource: sportNeedle
    highlightSource: sportHighlight

    Image {
        id: icon
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: 15
        source: "images/oil-temp.png"
    }

    Text {
        anchors.horizontalCenter: icon.horizontalCenter
        anchors.horizontalCenterOffset: -7
        anchors.bottom: icon.top
        anchors.bottomMargin: 110
        width: 5; height: width
        text: "Hot"
        color: "#cadfff"
        font.pixelSize: 12
        font.family: "Sarabun"
    }
    Text {
        anchors.horizontalCenter: icon.horizontalCenter
        anchors.horizontalCenterOffset: -7
        anchors.top: icon.bottom
        anchors.topMargin: 95
        width: 5; height: width
        text: "Cool"
        color: "#cadfff"
        font.pixelSize: 12
        font.family: "Sarabun"


    }
}


