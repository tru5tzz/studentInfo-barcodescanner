cmake_minimum_required(VERSION 3.5)

project(student-id VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)

#qt_standard_project_setup()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Quick QuickControl)

qt_add_executable(student-id
        main.cpp
)

add_library(mybackend STATIC
                Backend.h
                Backend.cpp
)
target_link_libraries(mybackend PRIVATE Qt6::Core)
target_include_directories(mybackend INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(myinterface STATIC
                interface.cpp
                interface.h
                )
target_link_libraries(myinterface PRIVATE Qt6::Core)
target_include_directories(myinterface INTERFACE ${CMAKE_CURRENT_SOUCE_DIR})

qt_add_qml_module(student-id
    URI com.trungnd.studentInfo
    VERSION 1.0
    QML_FILES
        mainWindows.qml
        Qt6ScannerOverlay.qml
)

target_link_libraries(student-id PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Core Qt6::Quick
                                myinterface
                                mybackend
)


add_subdirectory(test)
