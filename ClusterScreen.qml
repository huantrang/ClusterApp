import QtQuick

Item {
    id: root;
    Item {
        id: gauges
        opacity: MainModel.gaugesOpacity;

        Gauge {
            id: leftGauge;
            x: 20;
            y: 44;
            leftPosition: true;
            value: Units.kilometersToLongDistanceUnit(0)
            maxValue: Units.maximumSpeed
            textLabel: Units.speedUnit

            // SpeedWarningIndicator {
            //     id: speedWarningIndicator
            //     x: 218 - width/2
            //     y: 271 - height/2
            //     transform: Scale {
            //         origin.x: 60 - speedWarningIndicator.x
            //         origin.y: 340 - speedWarningIndicator.y
            //         xScale: leftGauge.scale
            //         yScale: leftGauge.scale
            //     }
            // }
        }

        Gauge {
            id: rightGauge;
            x: root.width - rightGauge.width - 20;
            y: 44;
            value: 10000 / 1000;
            valueText: "10"
            maxValue: 100000 / 1000;
            maxAngle: 180
            textLabel: ""

            //             StaticText {
            //                 id: rpmLabel
            //                 anchors.centerIn: parent
            //                 anchors.horizontalCenterOffset: -35
            //                 anchors.verticalCenterOffset: 100

            //                 opacity: 0.2
            //                 horizontalAlignment: Text.AlignRight
            //                 text: "x1000\n    RPM"
            //                 color: Style.lightPeriwinkle;
            //                 font.pixelSize: 10
            //                 font.family: "Sarabun"

            //                 transform: Scale {
            //                     origin.x: rightGauge.transformOriginX - rpmLabel.x
            //                     origin.y: 340 - rpmLabel.y
            //                     xScale: rightGauge.scale
            //                     yScale: rightGauge.scale
            //                 }
            //             }
        }

        Behavior on opacity { NumberAnimation { duration: 1000} }
    }

}
