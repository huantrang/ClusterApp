import QtQuick

Row {
    id: telltales;
    TellTalesIndicator
    {
        source: "images/left_arrow.png";
        active: TelltaleViewModel.leftArrowActive;
        blinking: TelltaleViewModel.leftArrowActive;
    }
    TellTalesIndicator
    {
        source: "images/doors.png";
        active: TelltaleViewModel.doorsActive;
    }
    TellTalesIndicator
    {
        source: "images/wheel.png";
        active: TelltaleViewModel.wheelActive;
    }
    TellTalesIndicator
    {
        source: "images/seat_belt.png";
        active: TelltaleViewModel.seatBeltActive;
    }
    TellTalesIndicator
    {
        source: "images/brake_system_warning.png";
        active: TelltaleViewModel.brakeSystemActive;
    }
    TellTalesIndicator
    {
        source: "images/parking-lights.png";
        active: TelltaleViewModel.parkingLightsActive;
    }
    TellTalesIndicator
    {
        source: "images/malfunction-indicador.png";
        active: TelltaleViewModel.malfunctionActive;
    }
    TellTalesIndicator
    {
        source: "images/high_beams.png";
        active: TelltaleViewModel.highBeamsActive;
    }
    TellTalesIndicator
    {
        source: "images/oil.png";
        active: TelltaleViewModel.oilActive;
    }
    TellTalesIndicator
    {
        source: "images/right_arrow.png";
        active: TelltaleViewModel.rightArrowActive;
        blinking: TelltaleViewModel.rightArrowActive;
    }
}
