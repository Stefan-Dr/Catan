QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.



DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CXXFLAGS += --coverage


QMAKE_LFLAGS += --coverage

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/bank.cpp \
    sources/board.cpp \
    sources/dice.cpp \
    sources/field.cpp \
    sources/game.cpp \
    sources/gui_node.cpp \
    sources/gui_road.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/node.cpp \
    sources/player.cpp \
    sources/road.cpp \

HEADERS += \
    headers/board.h \
    headers/color.h \
    headers/dice.h \
    headers/field.h \
    headers/game.h \
    headers/gui_node.h \
    headers/gui_road.h \
    headers/mainwindow.h \
    headers/player.h\
    headers/node.h\
    headers/bank.h\
    headers/resourcetype.h\
    headers/road.h\


FORMS += \
    forms/mainwindow.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    resource.qrc

SUBDIRS += \
    ../Tests/Tests.pro


