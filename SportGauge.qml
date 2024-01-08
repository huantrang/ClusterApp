import QtQuick
Gauge {
    id: root
    needleOffsetY: -13
    labelHorizontalCenterOffset: -11
    valueHorizontalCenterOffset: -11
    value: SpeedViewModel.Speed
    maxValue: 200
    textLabel: SpeedViewModel.Unit
    gaugeSource: sportGauge
    needleSource: sportNeedle
    highlightSource: sportHighlight
}
