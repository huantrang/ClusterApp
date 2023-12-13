import QtQuick

Gauge {
    id: root
    needleOffsetY: -13
    labelHorizontalCenterOffset: -11
    valueHorizontalCenterOffset: -11

    gaugeSource: sportGauge
    needleSource: sportNeedle
    highlightSource: sportHighlight
}
