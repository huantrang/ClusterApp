/******************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Quick Ultralite module.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
******************************************************************************/

import QtQuick

Item {
    id: laneAssist

    property real redBorderOpacity: 0
    property real scale: 1

    Image {
        id: leftLaneAssist
        source: "images/lanes/red-border-left.png"
        opacity: redBorderOpacity
        x: 306
        y: 280
        width: 70
        height: 200

        transform: Scale {
            origin.x: laneAssist.width / 2 - leftLaneAssist.x
            origin.y: laneAssist.height - leftLaneAssist.y

            xScale: laneAssist.scale
            yScale: laneAssist.scale
        }
    }

    Image {
        id: rightLaneAssist
        source: "images/lanes/red-border-right.png"
        opacity: redBorderOpacity
        x: 424
        y: 280
        width: 70
        height: 200

        transform: Scale {
            origin.x: laneAssist.width / 2 - rightLaneAssist.x
            origin.y: laneAssist.height - rightLaneAssist.y

            xScale: laneAssist.scale
            yScale: laneAssist.scale
        }
    }

    SequentialAnimation {
        id: laneAssistAnimation
        loops: Animation.Infinite
        alwaysRunToEnd: true

        NumberAnimation {
            target: laneAssist
            property: "redBorderOpacity"
            from: 0
            to: 0.7
            easing.type: Easing.OutQuad
            duration: 600
        }

        NumberAnimation {
            target: laneAssist
            property: "redBorderOpacity"
            from: 0.7
            to: 0
            easing.type: Easing.InQuad
            duration: 600
        }

        PauseAnimation {
            duration: 300
        }
    }


    Connections {
        target: LaneAssistViewModel
        function onSideChanged() {
            // console.log("Side changed to:", LaneAssistViewModel.side);
            leftLaneAssist.visible = LaneAssistViewModel.side === 0;
            rightLaneAssist.visible = LaneAssistViewModel.side === 1;
            if (LaneAssistViewModel.side === 0 || LaneAssistViewModel.side === 1)
                laneAssistAnimation.start();
        }
    }


    LaneAssistWhiteLine {
        t: t0
        scale: laneAssist.scale
        location: LaneAssistWhiteLine.Left
    }

    LaneAssistWhiteLine {
        t: t1 > 1 ? t1 - 1 : t1
        scale: laneAssist.scale
        location: LaneAssistWhiteLine.Left
    }

    LaneAssistWhiteLine {
        t: t0
        scale: laneAssist.scale
        location: LaneAssistWhiteLine.Right
    }

    LaneAssistWhiteLine {
        t: t1 > 1 ? t1 - 1 : t1
        scale: laneAssist.scale
        location: LaneAssistWhiteLine.Right
    }

    property real t0: 0
    property real t1: t0 + 0.5

    property int t0Duration: calculateDuration(SpeedViewModel.Speed)
    property int lastDuration: -1

    function calculateDuration(speed) {
        if (speed > 0 && speed < 30)
            return 3000;
        else if (speed >= 30 && speed < 60)
            return 1500;
        else if (speed >= 60 && speed < 100)
            return 1000;
        else if (speed >= 100 && speed < 150)
            return 500;
        else
            return 200;
    }

    Binding {
        target: laneAssist
        property: "t0Duration"
        value: laneAssist.calculateDuration(SpeedViewModel.Speed)
    }

    NumberAnimation {
        id: t0Animation
        target: laneAssist
        property: "t0"
        from: 0
        to: 1
        loops: Animation.Infinite
        duration: t0Duration
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            if (t0Duration !== lastDuration && SpeedViewModel.Speed > 0) {
                lastDuration = t0Duration;
                t0Animation.stop();
                t0Animation.start();
            }
        }
    }

}
