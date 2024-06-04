cmake_minimum_required(VERSION 3.16)

project(Catan-azrs VERSION 1.0.0 LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


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

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.h)

# Kreiranje biblioteke sa izvornim fajlovima i zaglavljima
add_library(MyLibrary ${HEADERS} ${SOURCES})

#Postavljamo promenljivu FORMS da bude putanja do curr_path/forms/mainwindow.ui
#Za otvaranje pocetnog prozora
set(FORMS ${CMAKE_CURRENT_SOURCE_DIR}/forms/mainwindow.ui)

qt5_wrap_ui(UI_HEADERS ${FORMS})

# Dodavanje resursa u biblioteku
target_sources(MyLibrary PRIVATE ${RESOURCES} ${UI_HEADERS})

# Povezivanje Qt biblioteka sa bibliotekom
target_link_libraries(MyLibrary PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)

# Kreiranje izvršne datoteke i povezivanje sa bibliotekom
add_executable(${PROJECT_NAME} ${FORMS})

target_link_libraries(${PROJECT_NAME} PRIVATE MyLibrary)
# target_link_libraries(prog ${CONAN_LIBS})


