import QtQuick

NormalModeContentItem {
    id: root

    property string textColor: "#CADFFF"
    property string textFont: "Inter"

    Row {
        id: mainRow
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 4
        Row {
            id: distance
            spacing: 1

            Text {
                text: NaviViewModel.filteredDistanceToNextManoeuver
                font.pixelSize: 13
                font.family: textFont
                font.bold: true
                font.italic: true
                color: textColor
            }

            Text {
                text: "m"
                font.pixelSize: 11
                font.family: textFont
                color: textColor
                font.bold: true
                font.italic: true
            }
        }

        Text {
            text: "-"
            font.pixelSize: 11
            font.family: textFont
            color: textColor
        }

        Text {
            text: NaviViewModel.instruction
            font.pixelSize: 11
            font.family: textFont
            font.bold: true
            font.italic: true
            color: textColor
        }

        Text {
            text: "-"
            font.pixelSize: 11
            font.family: textFont
            color: textColor
        }

        Text {
            text: NaviViewModel.street
            font.pixelSize: 11
            font.family: textFont
            font.bold: true
            font.italic: true
            color: textColor
        }

    }
}
