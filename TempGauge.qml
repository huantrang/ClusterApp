import QtQuick

BaseGauge {
    id: root;
    needleOffsetY: -13
    needleOffsetX: -1
    value: TempViewModel.Temp;
    maxValue: TempViewModel.MaxTemp;
    gaugeSource: sportGauge
    needleSource: sportNeedle
    highlightSource: sportHighlight

    Image {
        id: icon
        anchors.centerIn: parent
        //anchors.horizontalCenterOffset: 15
        source: "images/oil-temp.png"
    }

    Text {
        id: label
        anchors.horizontalCenter: icon.horizontalCenter
        // anchors.horizontalCenterOffset: -7.5
        anchors.topMargin: 10
        anchors.top: icon.bottom;
        opacity: 0.8
        text: value.toFixed(0)
        color: "#cadfff";
        font.pixelSize: 13;
        font.bold: true;
        font.family: "Roboto";
        transform: Scale {
            origin.x: transformOriginX - label.x
            origin.y: 340 - label.y
            xScale: root.scale
            yScale: root.scale
        }
    }

    Text {
        id: labelUnit
        anchors.horizontalCenter: icon.horizontalCenter
        anchors.topMargin: 10
        anchors.top: icon.bottom
        anchors.left: label.right
        opacity: 0.8
        text: TempViewModel.TempUnit
        color: "#cadfff";
        font.pixelSize: 13;
        font.bold: true;
        font.family: "Roboto";
        transform: Scale {
            origin.x: transformOriginX - label.x
            origin.y: 340 - label.y
            xScale: root.scale
            yScale: root.scale
        }
    }

    Text {
        anchors.horizontalCenter: icon.horizontalCenter
        anchors.horizontalCenterOffset: -11.5
        anchors.bottom: icon.top
        anchors.bottomMargin: 110
        width: 5; height: width
        text: "Hot"
        color: "#ff0000"
        font.pixelSize: 12
        font.family: "Roboto"
    }
    Text {
        anchors.horizontalCenter: icon.horizontalCenter
        anchors.horizontalCenterOffset: -11.5
        anchors.top: icon.bottom
        anchors.topMargin: 95
        width: 5; height: width
        text: "Cool"
        color: "#cadfff"
        font.pixelSize: 12
        font.family: "Roboto"
    }
}


