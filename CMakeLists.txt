cmake_minimum_required(VERSION 3.5)

project(student-id VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Quick QuickControl)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)

qt_add_executable(student-id
        main.cpp
)

qt_add_qml_module(student-id
    URI hello
    VERSION 1.0
    QML_FILES
        mainWindows.qml
)

target_link_libraries(student-id PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Core Qt6::Quick)
