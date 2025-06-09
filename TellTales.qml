import QtQuick

Row {
    id: telltales;
    TellTalesIndicator
    {
        source: "images/left_arrow.png";
        active: true;
        blinking: true;
    }
    TellTalesIndicator
    {
        source: "images/doors.png";
        active: false;
    }
    TellTalesIndicator
    {
        source: "images/wheel.png";
        active: false;
    }
    TellTalesIndicator
    {
        source: "images/seat_belt.png";
        active: false;
    }
    TellTalesIndicator
    {
        source: "images/brake_system_warning.png";
        active: false;
    }
    TellTalesIndicator
    {
        source: "images/parking-lights.png";
        active: false;
    }
    TellTalesIndicator
    {
        source: "images/malfunction-indicador.png";
        active: true;
    }
    TellTalesIndicator
    {
        source: "images/high_beams.png";
        active: true;
    }
    TellTalesIndicator
    {
        source: "images/oil.png";
        active: true;
    }
    TellTalesIndicator
    {
        source: "images/right_arrow.png";
        active: false;
        blinking: false;
    }
}
