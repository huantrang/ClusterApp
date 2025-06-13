cmake_minimum_required(VERSION 3.16)

project(Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.3.0/gcc_64")

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)

qt_add_executable(AppCluster
    main.cpp
    speedviewmodel.h speedviewmodel.cpp
    gearshiftviewmodel.h gearshiftviewmodel.cpp
    tempviewmodel.h tempviewmodel.cpp
    naviviewmodel.h naviviewmodel.cpp
    laneassistviewmodel.h laneassistviewmodel.cpp
    TelltaleViewModel.h TelltaleViewModel.cpp
    model/gearshiftmodel.cpp model/gearshiftmodel.h
    model/laneassistmodel.cpp model/laneassistmodel.h
    model/navimodel.cpp model/navimodel.h
    model/telltalemodel.cpp model/telltalemodel.h
    model/tempmodel.cpp model/tempmodel.h
    model/speedmodel.cpp model/speedmodel.h
    socket/TcpReceiver.h socket/TcpReceiver.cpp
    model/basemodel.h
)
# Resources:
set(qml_resource_files
    "images/gauge-gauge-frame.png"
    "images/car-highlights.png"
    "images/bg-mask.png"
    "images/highlight-normal.png"
    "images/needle-normal.png"
    "images/top-line.png"
    "images/oil-temp.png"
    "images/gauge-gauge-frame-sport-center.png"
    "images/gauge-gauge-frame-sport-side.png"
    "images/needle-standard-sport.png"
    "images/highlight-big-sport.png"
    "images/speed-limit-warnings/140.png"
    "images/speed-limit-warnings/90.png"
    "images/speed-limit-warnings/70.png"
    "images/speed-limit-warnings/50.png"
    "images/speed-limit-warnings/30.png"
    "images/fuel.png"
    "images/battery.png"
    "images/doors.png"
    "images/wheel.png"
    "images/right_arrow.png"
    "images/left_arrow.png"
    "images/seat_belt.png"
    "images/brake_system_warning.png"
    "images/parking-lights.png"
    "images/high_beams.png"
    "images/malfunction-indicador.png"
    "images/oil.png"
    "images/arrows/arrow-straight.png"
    "images/arrows/arrow-right-45.png"
    "images/arrows/arrow-right-90.png"
    "images/arrows/arrow-right-round.png"
    "images/arrows/arrow-left-45.png"
    "images/arrows/arrow-left-90.png"
    "images/arrows/arrow-left-round.png"
    "images/lanes/red-border-left.png"
    "images/lanes/red-border-right.png"
    "images/lanes/white-line-left.png"
    "images/lanes/white-line-right.png"
    "Main.qml"
    "BaseGauge.qml"
    "Gauge.qml"
    "ClusterScreen.qml"
    "SpeedLimitImage.qml"
    "Units.qml"
    "SpeedLimitIndicator.qml"
    "SpeedLimitValues.qml"
    "MiddleGauge.qml"
    "SpeedGauge.qml"
    "TempGauge.qml"
    "LinearGauge.qml"
    "TellTalesIndicator.qml"
    "TellTales.qml"
    "GuideArrow.qml"
    "GuideArrowItem.qml"
    "Navi.qml"
    "NormalModeContentItem.qml"
    "LaneAssist.qml"
    "LaneAssistWhiteLine.qml"
)

qt_add_resources(AppCluster "qml"
    PREFIX
    "/"
    FILES
    ${qml_resource_files}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(AppCluster PROPERTIES
    #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AppCluster
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(AppCluster
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS AppCluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
