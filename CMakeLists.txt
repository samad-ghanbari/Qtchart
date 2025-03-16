cmake_minimum_required(VERSION 3.16)

project(QtChart1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appQtChart1
    main.cpp
)

qt_add_qml_module(appQtChart1
    URI QtChart1
    VERSION 1.0
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQtChart1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQtChart1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQtChart1
    PRIVATE Qt6::Quick
)

# chart library
# use QApplication in main.cpp
find_package(Qt6 REQUIRED COMPONENTS Charts)
target_link_libraries(appQtChart1 PRIVATE Qt6::Charts)

# printsupport
find_package(Qt6 REQUIRED COMPONENTS  PrintSupport)
target_link_libraries(appQtChart1 PRIVATE  Qt6::PrintSupport)


include(GNUInstallDirs)
install(TARGETS appQtChart1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
