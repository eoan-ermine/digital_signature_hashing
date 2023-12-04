cmake_minimum_required(VERSION 3.27)
project(hashing_techniques)

set(CMAKE_CXX_STANDARD 23)
include_directories(hashing_techniques)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_add_executable(hashing_techniques hashing_techniques/main.cpp
        hashing_techniques/forms/mainwindow.cpp
        hashing_techniques/forms/mainwindow.hpp)

set_target_properties(hashing_techniques PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
)

target_link_libraries(hashing_techniques  PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
