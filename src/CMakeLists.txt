cmake_minimum_required(VERSION 3.16)

project(Catan-azrs VERSION 1.0.0 LANGUAGES CXX)

#Postavljamo standard da bude c++17 
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

#Postavljamo promenljivu CURRENT_PATH da bude putanja do trenutnog foldera
set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resource.qrc)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

find_package(Qt5Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

find_package(Qt5Gui REQUIRED)

find_package(Qt5 COMPONENTS Network REQUIRED)

qt5_add_resources(RES_SOURCES ${RESOURCES})

#Definisemo promenljive HEADERS i SOURCES
set(HEADERS
    ${CURRENT_PATH}/headers/mainwindow.h
    ${CURRENT_PATH}/headers/player.h 
    ${CURRENT_PATH}/headers/game.h 
    ${CURRENT_PATH}/headers/board.h 
    ${CURRENT_PATH}/headers/field.h
    ${CURRENT_PATH}/headers/bank.h
    ${CURRENT_PATH}/headers/dice.h
    ${CURRENT_PATH}/headers/node.h
    ${CURRENT_PATH}/headers/gui_node.h
    ${CURRENT_PATH}/headers/road.h
    ${CURRENT_PATH}/headers/gui_road.h
    ${CURRENT_PATH}/headers/resourcetype.h
)

set(SOURCES
    ${CURRENT_PATH}/sources/mainwindow.cpp
    ${CURRENT_PATH}/sources/main.cpp 
    ${CURRENT_PATH}/sources/player.cpp 
    ${CURRENT_PATH}/sources/game.cpp 
    ${CURRENT_PATH}/sources/board.cpp 
    ${CURRENT_PATH}/sources/field.cpp
    ${CURRENT_PATH}/sources/bank.cpp
    ${CURRENT_PATH}/sources/dice.cpp
    ${CURRENT_PATH}/sources/node.cpp
    ${CURRENT_PATH}/sources/gui_node.cpp
    ${CURRENT_PATH}/sources/road.cpp
    ${CURRENT_PATH}/sources/gui_road.cpp
)

#Postavljamo promenljivu FORMS da bude putanja do curr_path/forms/mainwindow.ui
#Za otvaranje pocetnog prozora
set(FORMS ${CMAKE_CURRENT_SOURCE_DIR}/forms/mainwindow.ui)

qt5_wrap_ui(UI_HEADERS ${FORMS})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${FORMS} ${RESOURCES})

qt5_use_modules(${PROJECT_NAME} Core Gui Widgets Network)



