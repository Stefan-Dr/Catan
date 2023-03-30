cmake_minimum_required(VERSION 3.16.3)

project(Catan VERSION 1.0.0 LANGUAGES CXX)

set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resource.qrc)
qt5_add_resources(RES_SOURCES ${RESOURCES})

set(SOURCES
    ${SRC_PATH}/sources/bank.cpp
    ${SRC_PATH}/sources/board.cpp
    ${SRC_PATH}/sources/dice.cpp
    ${SRC_PATH}/sources/field.cpp    
    ${SRC_PATH}/sources/game.cpp
    ${SRC_PATH}/sources/gui_node.cpp
    ${SRC_PATH}/sources/gui_road.cpp
    ${SRC_PATH}/sources/main.cpp
    ${SRC_PATH}/sources/mainwindow.cpp
    ${SRC_PATH}/sources/node.cpp
    ${SRC_PATH}/sources/player.cpp
    ${SRC_PATH}/sources/road.cpp
)

set(HEADERS
    ${SRC_PATH}/headers/bank.h
    ${SRC_PATH}/headers/board.h
    ${SRC_PATH}/headers/dice.h
    ${SRC_PATH}/headers/field.h
    ${SRC_PATH}/headers/game.h
    ${SRC_PATH}/headers/gui_node.h
    ${SRC_PATH}/headers/gui_road.h
    ${SRC_PATH}/headers/mainwindow.h
    ${SRC_PATH}/headers/node.h
    ${SRC_PATH}/headers/player.h
    ${SRC_PATH}/headers/road.h
    ${SRC_PATH}/headers/resourcetype.h
    ${SRC_PATH}/headers/color.h
)

set(UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/forms/mainwindow.ui
)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${UI_HEADERS} ${RESOURCES})

qt5_use_modules(${PROJECT_NAME} Core Gui Widgets Network)

