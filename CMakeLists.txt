cmake_minimum_required(VERSION 3.16)

project(Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)

qt_add_executable(AppCluster
    main.cpp
)
# Resources:
set(qml_resource_files
    "images/gauge-gauge-frame.png"
    "images/highlight-normal.png"
    "images/needle-normal.png"
    "Main.qml"
    "BaseGauge.qml"
    "Gauge.qml"
    "ClusterScreen.qml"
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
