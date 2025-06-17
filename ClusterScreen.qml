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
            font.family: "Helvetica Neue"
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

    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        x : 30
        spacing: 30 // khoảng cách giữa ODO và RANGE, bạn có thể điều chỉnh

        Row {
            spacing: 4
            Text {
                id: range
                text: "RANGE"
                color: "#32CD32"
                font.pixelSize: 14
                font.family: "Helvetica Neue"
            }
            Text {
                id: rangeValue
                text: String(Math.round(1000 * (CommonViewModel.batteryValue + CommonViewModel.fuelValue) / 2))
                color: "#cadfff"
                font.pixelSize: 14
                font.family: "Helvetica Neue"
            }
            Text {
                id: rangeUnit
                text: "km"
                color: "#32CD32"
                font.pixelSize: 10
                font.family: "Helvetica Neue"
            }
        }

        Row {
            spacing: 4
            Text {
                id: odo
                text: "ODO"
                color: "#32CD32"
                font.pixelSize: 14
                font.family: "Helvetica Neue"
            }
            Text {
                id: odoValue
                text: CommonViewModel.odoValue
                color: "#cadfff"
                font.pixelSize: 14
                font.family: "Helvetica Neue"
            }
            Text {
                id: odoUnit
                text: "km"
                color: "#32CD32"
                font.pixelSize: 10
                font.family: "Helvetica Neue"
            }
        }
    }

    LinearGauge {
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 40;
        x: 534;
        image: "images/fuel.png";
        emptyText: "E";
        value: CommonViewModel.fuelValue;
    }

    LinearGauge {
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 40;
        x: 660;
        image: "images/battery.png";
        emptyText: "E";
        value: CommonViewModel.batteryValue;
    }

    TellTales {
        anchors.horizontalCenter: parent.horizontalCenter;
        y:16;
        visible: true
    }

    GuideArrowItem {
        id:guideArrowItem
        anchors.fill: parent
        scale: root.scale
    }

    Navi
    {
        id:naviComponent
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        activeMode: guideArrowItem.visible
    }

    LaneAssist {
        anchors.fill: parent
        scale: root.scale
    }



}
