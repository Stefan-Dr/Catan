TEMPLATE = app
QT += core gui

CONFIG += c++11

isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
!isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

isEmpty(CATCH_INCLUDE_DIR): {
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
}

SOURCES +=     main.cpp     \
    ../src/bank.cpp \
    ../src/dice.cpp \
    ../src/node.cpp \
    ../src/road.cpp \
    ../src/player.cpp
    bank_tests.cpp

HEADERS += \
    ../src/bank.h \
    ../src/dice.h \
    ../src/node.h \
    ../src/road.h \
    ../src/player.h
    catch.hpp
