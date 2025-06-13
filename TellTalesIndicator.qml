import QtQuick

Item {
    id: indicator
    height: 28
    width: image.width + 15

    property alias source: image.source
    property bool active: false
    property color activeColor: "#19f801"
    property color inactiveColor: "#001b4d"
    property alias blinking: indicatorBlinkAnimation.running

    Image {
        id: image
        width: 24
        height: 24
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: active === true ? 1 : 0.1
        Behavior on opacity { NumberAnimation {
            easing.type: Easing.InOutQuad
            duration: 200
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
