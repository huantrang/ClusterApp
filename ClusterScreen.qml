import QtQuick

Item {
    id: root;

    MiddleGauge {
        id: middleGauge
        leftPosition: true
        anchors.horizontalCenter: parent.horizontalCenter
        valueVerticalCenterOffset: -27
        y: 62;
        value: 2;
        maxValue: 10;
        valueText: "D"
        textLabel: "Gear shift"
        maxAngle: 285
        minAngle: 45
        labelOpacity: 1
        opacity: 1;

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenterOffset: -105
            anchors.verticalCenterOffset: 95

            opacity: 0.2
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
        SportGauge {
            id: leftGauge;
            x: 20
            y: 44;
            leftPosition: true;
            value: 50
            maxValue: 200
            textLabel: "km/h"
            valueTextScale: 0.8;
            valueHorizontalCenterOffset: -20;
            labelHorizontalCenterOffset: -18;
            labelVerticalOffset: -5;

            Component.onCompleted:
            {
                console.log(leftGauge.x);
            }
        }

        TempGauge {
            id: rightGauge;
            x: root.width - rightGauge.width - 20;
            y: 44;
            value: 50;
            maxValue: 180;
            maxAngle: 180;

            opacity: 1;
        }
    }

}
