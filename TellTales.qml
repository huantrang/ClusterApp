import QtQuick

Row {
    id: telltales;

    TellTalesIndicator
    {
        source: "images/turn_left.png";
        activeColor: "#19f801";
        active: true;
        imageOpacity: 1;
        blinking: true;
    }
    TellTalesIndicator
    {
        source: "images/beam.png";
        activeColor: "#19f801";
        active: false;
        imageOpacity: 1;
    }
    TellTalesIndicator
    {
        source: "images/high-beams.png";
        activeColor: "#0066ff";
        active: false;
        imageOpacity: 1;
    }
    TellTalesIndicator
    {
        source: "images/ready.png";
        activeColor: "#19f801";
        active: false;
        imageOpacity: 1;
    }
    TellTalesIndicator
    {
        source: "images/parked.png";
        activeColor: "#ff0000";
        active: false;
        imageOpacity: 1;
    }
    TellTalesIndicator
    {
        source: "images/airbag.png";
        activeColor: "#ff0000";
        active: false;
        imageOpacity: 1
    }
    TellTalesIndicator
    {
        source: "images/turn_right.png";
        activeColor: "#19f801";
        active: false;
        imageOpacity: 1;
        blinking: true;
    }
}
