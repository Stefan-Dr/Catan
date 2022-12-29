TEMPLATE = app
QT += gui

CONFIG += c++11

isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
!isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

isEmpty(CATCH_INCLUDE_DIR): {
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
}

SOURCES +=     main.cpp     \
    ../src/sources/bank.cpp \
    ../src/sources/dice.cpp \
    ../src/sources/node.cpp \
    ../src/sources/road.cpp \
    bank_tests.cpp \
    dice_tests.cpp \
    node_tests.cpp \
    road_tests.cpp

HEADERS += \
    ../src/headers/bank.h \
    ../src/headers/dice.h \
    ../src/headers/node.h \
    ../src/headers/road.h \
    catch.hpp
