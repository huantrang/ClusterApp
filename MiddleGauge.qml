import QtQuick

BaseGauge {
    id: root;
    property alias textLabel: label.text;
    property alias valueText: textValue.text;
    property double labelOpacity: 1
    property int labelHorizontalCenterOffset: 0
    property int labelVerticalOffset: 0
    property int valueVerticalCenterOffset: -7
    property int valueHorizontalCenterOffset: 0
    needleOffsetX: -1
    needleOffsetY: -38
    highlightOffsetX: 1
    highlightOffsetY: -22

    gaugeSource: "images/gauge-gauge-frame-sport-center.png"
    needleSource: sportNeedle
    highlightSource: sportHighlight

    Repeater {
        model: 11;
        delegate: Text {
            visible: index <= Math.ceil(maxValue / interval); // Ideally, the model would be dinamic and this not needed
            property real angle: minAngle + 2 * Math.PI * index * interval / maxValue * (maxAngle - minAngle) / 360;
            x: (root.width - width) / 2 + (root.left ? -1 : 1) * Math.sin(angle) * root.scale * 135;
            y: (root.height - height) / 2 + Math.cos(angle) * root.scale * 135;
            text: index * interval;
            color: "#cadfff";
            font.pixelSize: 12;
            font.bold: false;
            font.family: "Sarabun";
            opacity: {
                var distance = Math.abs(animatedValue/interval - index);
                var alphaResult = 1.5 - (distance / 1.25);
                return Math.min(Math.max(alphaResult, 0), 1);
            }
            Behavior on opacity { NumberAnimation { duration: 150; } }
        }
    }

    Text {
        id: textValue
        anchors.centerIn: parent
        anchors.verticalCenterOffset: valueVerticalCenterOffset * root.scale
        anchors.horizontalCenterOffset: valueHorizontalCenterOffset
        opacity: labelOpacity
        horizontalAlignment: Text.AlignHCenter
        text: value.toFixed(0);
        color: "#cadfff";
        font.pixelSize: 64;
        font.bold: true;
        font.family: "Sarabun";

        Behavior on opacity { NumberAnimation { duration: 250 } }
    }

    Text {
        id: label
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: labelHorizontalCenterOffset
        anchors.topMargin: labelVerticalOffset
        anchors.top: textValue.bottom;


        opacity: labelOpacity
        color: "#cadfff";
        font.pixelSize: 16;
        font.bold: false;
        font.family: "Sarabun";
    }
}


