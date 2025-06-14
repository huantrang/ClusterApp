import QtQuick

Item {

    id: root;
    property bool leftPosition;
    property real value;
    property real minAngle: 0
    property int needleOffsetX: 0
    property int needleOffsetY: 0
    property int highlightOffsetX: 0
    property int highlightOffsetY: 0
    property int maxValue : 1; // The maximum value shown in this gauge
    property int maxAngle : 200; // The angle in degrees at which the needle is when the value is maxValue
    property alias gaugeSource: bg.source;
    property alias needleSource: needle.source
    property alias highlightSource: highlight.source

    property string sportGauge: "images/gauge-gauge-frame-sport-side.png";
    property string sportNeedle: "images/needle-standard-sport.png"
    property string sportHighlight: "images/highlight-big-sport.png"

    width: 340;
    height: 340;

    property int transformOriginX: leftPosition ? 60 : 280

    property real scale: 1;
    property int interval: maxValue > 140 ? 20 : maxValue > 50 ? 10 : 1;
    property real animatedValue: value;
    Behavior on animatedValue { NumberAnimation {
            easing.type: Easing.OutQuad;
            duration: 100; //fix me
        } }

    Image {
        id: bg;
        width: implicitWidth
        height: implicitHeight
        anchors.centerIn: parent;
        source: "images/gauge-gauge-frame.png"
        transform: [
            Scale {
                origin.x: bg.implicitWidth / 2;
                xScale: leftPosition ? 1 : -1;
            },
            Scale {
                origin.x: transformOriginX - bg.x
                origin.y: 340 - bg.y
                xScale: root.scale
                yScale: root.scale
            }
        ]
    }

    Image {
        id: highlight
        x: 112 + highlightOffsetX
        y: -3 + highlightOffsetY
        width: implicitWidth
        height: implicitHeight
        source: "images/highlight-normal.png"

        transform: [
            Rotation {
                origin.x: 340 / 2 - highlight.x;
                origin.y: 340 / 2 - highlight.y - 0.5;
                angle: minAngle/0.0174532925 + 180 + animatedValue * (leftPosition ? 1 : -1) * (maxAngle - minAngle) / maxValue
            },
            Scale {
                origin.x: transformOriginX - highlight.x
                origin.y: 340 - highlight.y - 0.5
                xScale: root.scale
                yScale: root.scale
            },
            Translate {
                y: 0.5
            }
        ]
    }

    Image {
        id: needle
        x: 171 - needle.width/2 + needleOffsetX
        y: 16 + needleOffsetY
        width: implicitWidth
        height: implicitHeight
        source: "images/needle-normal.png"

        transform: [
            Rotation {
                origin.x: 340 / 2 - needle.x;
                origin.y: 340 / 2 - needle.y;
                angle: minAngle/0.0174532925 + 180 + animatedValue * (leftPosition ? 1 : -1) * (maxAngle - minAngle) / maxValue
            },
            Scale {
                origin.x: transformOriginX - needle.x
                origin.y: 340 - needle.y
                xScale: root.scale
                yScale: root.scale
            }
        ]
    }
}
