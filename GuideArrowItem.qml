import QtQuick 2.15

Item {
    id: root

    property real scale: 1
    property int arrowType: NaviViewModel.arrowType

    visible: arrowType !== 0

    property bool _newArrowPending: false;

    GuideArrow {
        id: arrow
        scale: root.scale
        xOrigin: root.width / 2
        yOrigin: root.height
        direction: root.direction

    }

    property bool _arrowSwitchAnimationActive: false

    ParallelAnimation {
        running: true
        loops: Animation.Infinite

        NumberAnimation {
            target: arrow
            property: "arrowOffset"

            from: -8
            to: 0
            duration: 2400
        }

        SequentialAnimation {
            NumberAnimation {
                easing.type: Easing.InQuad
                duration: 150
                target: arrow
                property: "opacity"
                from: _arrowSwitchAnimationActive ? 0 : 1
                to: 1
            }
            ScriptAction {
                script: _arrowSwitchAnimationActive = false;
            }
            PauseAnimation {
                duration: 2100
            }
            ScriptAction {
                script: {
                    if (_newArrowPending) {
                        _arrowSwitchAnimationActive = true;
                        _newArrowPending = false;
                    }
                }
            }
            NumberAnimation {
                easing.type: Easing.OutQuad
                duration: 150
                target: arrow
                property: "opacity"
                from: 1
                to: _arrowSwitchAnimationActive ? 0 : 1
            }
            ScriptAction {
                script: if (_arrowSwitchAnimationActive) arrow.source = NaviViewModel.getArrowSource();
            }
        }
    }

    Component.onCompleted: arrow.source = NaviViewModel.getArrowSource()



    property int direction: 0

    Connections {
        target: NaviViewModel
        function onArrowTypeChanged() {
            _newArrowPending = true;
            direction = (NaviViewModel.arrowType === 1 ||
                         NaviViewModel.arrowType === 2 ||
                         NaviViewModel.arrowType === 3 ||
                         NaviViewModel.arrowType === 4) ? 1 : 0;
            arrow.source = NaviViewModel.getArrowSource();
        }
    }

}
