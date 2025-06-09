import QtQuick

Item {
    id: root;

    MiddleGauge {
        id: middleGauge
        leftPosition: true
        anchors.horizontalCenter: parent.horizontalCenter
        valueVerticalCenterOffset: -27
        y: 65;
        textLabel: "Gear shift"
        maxAngle: 285
        minAngle: 45
        labelOpacity: 1
        opacity: 1;
        transform: [
            Scale {
                origin.x: (middleGauge.width/2).toFixed(0)
                origin.y: (middleGauge.height/2).toFixed(0)
                xScale: 0.9
                yScale: 0.9
            }
        ]
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenterOffset: -105
            anchors.verticalCenterOffset: 95
            opacity: 0.6
            horizontalAlignment: Text.AlignRight
            text: "x1000\n    RPM"
            color: "#cadfff"
            font.pixelSize: 10
            font.family: "Sarabun"
        }
    }

    Item {
        id: gauges
        opacity: 1;

        SpeedLimitIndicator {
            opacity: leftGauge.opacity
            anchors.horizontalCenter: leftGauge.horizontalCenter
            anchors.horizontalCenterOffset: leftGauge.labelHorizontalCenterOffset
            y: 295
            width: 44
        }

        SpeedGauge {
            id: leftGauge;
            x: 20
            y: 44;
            leftPosition: true;
            valueTextScale: 0.6;
            valueHorizontalCenterOffset: -20;
            labelHorizontalCenterOffset: -18;
            labelVerticalOffset: -5;
            minAngle: 1
            maxAngle: 150
        }

        TempGauge {
            id: rightGauge;
            x: root.width - rightGauge.width - 20;
            y: 44;
            maxAngle: 180;
            minAngle: 0;
        }
    }

    Image {
        id: bg
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; }
        source: "images/bg-mask.png"

        transform: Scale {
            origin.x: bg.implicitWidth / 2
            origin.y: bg.implicitHeight

            xScale: 1
            yScale: 1
        }
    }
    Image {
        id: highlights
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; }
        source: "images/car-highlights.png"

        transform: Scale {
            origin.x: highlights.implicitWidth / 2
            origin.y: highlights.implicitHeight

            xScale: 1
            yScale: 1
        }
    }

    Text {
        id: odo
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 27;
        anchors.left: parent.left;
        anchors.leftMargin: 30;
        text: "ODO";
        color: "#657080"
        font.pixelSize: 12;
        font.family: "Sarabun";
    }
    Text {
        id: odoValue
        anchors.baseline: odo.baseline;
        anchors.left: odo.right;
        anchors.leftMargin: 4;
        text: "10000";
        color: "#cadfff";
        font.pixelSize: 20;
        font.family: "Sarabun";
    }
    Text {
        id: odoUnit
        anchors.baseline: odo.baseline;
        anchors.left: odoValue.right;
        anchors.leftMargin: 4;
        text: "km";
        color: "#657080"
        font.pixelSize: 12;
        font.family: "Sarabun";
    }

    Text {
        id: range
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 27;
        x: 170
        text: "RANGE";
        color: "#657080"
        font.pixelSize: 12;
        font.family: "Sarabun";
    }
    Text {
        id: rangeValue
        anchors.baseline: range.baseline;
        anchors.left: range.right;
        anchors.leftMargin: 4;
        text: "1";
        color: "#cadfff";
        font.pixelSize: 20;
        font.family: "Sarabun";
    }
    Text {
        id: rangeUnit
        anchors.baseline: range.baseline;
        anchors.left: rangeValue.right;
        anchors.leftMargin: 4;
        text: "km";
        color: "#657080"
        font.pixelSize: 12;
        font.family: "Sarabun";
    }

    LinearGauge {
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 27;
        x: 534;
        image: "images/fuel.png";
        emptyText: "E";
        value: 0.5;
    }

    LinearGauge {
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 27;
        x: 660;
        image: "images/battery.png";
        emptyText: "E";
        value: 0.7;
    }

    TellTales {
        anchors.horizontalCenter: parent.horizontalCenter;
        y:16;
        visible: true
    }


}
