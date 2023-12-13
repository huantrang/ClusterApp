import QtQuick

Image {
    property int limit
    visible: limit !== SpeedLimitValues.None
    source: {
        switch (limit) {
        case SpeedLimitValues.VerySlow:
            return "images/speed-limit-warnings/30.png"
        case SpeedLimitValues.Slow:
            return "images/speed-limit-warnings/50.png"
        case SpeedLimitValues.Medium:
            return "images/speed-limit-warnings/70.png"
        case SpeedLimitValues.Fast:
            return "images/speed-limit-warnings/90.png"
        default:
            return "images/speed-limit-warnings/140.png"
        }
    }
}
