import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Item {
    id: splash
    signal splashDone()

    Rectangle {
        anchors.fill: parent
        color: "#00091a"

        Text {
            id: textSource
            text: "UTC"
            font.pixelSize: 100
            font.bold: true
            color: "#ffffff"
            visible: false
        }


        Text {
            id: utcText
            text: "UTC"
            font.pixelSize: 100
            font.bold: true
            color: "white"
            anchors.verticalCenter: parent.verticalCenter
            x: -utcText.width
            opacity: 0.0
            scale: 0.8
        }

        SequentialAnimation {
            running: true

            NumberAnimation {
                target: utcText
                property: "x"
                to: (parent.width - utcText.width) / 2
                duration: 1800
                easing.type: Easing.OutBack
            }

            ParallelAnimation {
                NumberAnimation { target: utcText; property: "scale"; to: 1.0; duration: 800; easing.type: Easing.OutCubic }
                NumberAnimation { target: utcText; property: "opacity"; to: 1.0; duration: 800 }
            }

            PauseAnimation { duration: 1000 }

            ParallelAnimation {
                NumberAnimation { target: utcText; property: "opacity"; to: 0.0; duration: 1000 }
            }

            ScriptAction { script: splash.splashDone() }
        }
    }
}
