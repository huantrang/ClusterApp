import QtQuick

Item {
    id: indicator
    height: 28
    width: image.width + 15

    property alias source: image.source
    property bool active: false
    property color activeColor: "#19f801"
    property color inactiveColor: "#001b4d"
    property alias imageOpacity: image.opacity
    property alias blinking: indicatorBlinkAnimation.running

    Image {
        id: image
        source: indicator.active ? indicator.activeColor : indicator.inactiveColor
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        // ShaderEffect {
        //     anchors.fill: parent
        //     property variant source: ShaderEffectSource { sourceItem: image }
        //     property color color: indicator.active ? indicator.activeColor : indicator.inactiveColor
        //     Behavior on color { ColorAnimation {
        //         duration: 150
        //         easing.type: Easing.InOutQuad
        //     }}
        // }

        Behavior on opacity { NumberAnimation {
            easing.type: Easing.InOutQuad
            duration: TellTalesModel.opacityChangeDuration
        }}
    }

    SequentialAnimation {
        id: indicatorBlinkAnimation
        loops: Animation.Infinite
        alwaysRunToEnd: true

        ScriptAction {
            script: indicator.active = true
        }

        PauseAnimation {
            duration: 400
        }

        ScriptAction {
            script: indicator.active = false
        }

        PauseAnimation {
            duration: 300
        }
    }
}
