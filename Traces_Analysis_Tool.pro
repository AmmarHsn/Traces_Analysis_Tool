TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += \
        atom.cpp \
        experiment.cpp \
        main.cpp \
        mainwindow.cpp \
        robot.cpp \
        viewwidget.cpp

HEADERS += \
    atom.h \
    experiment.h \
    mainwindow.h \
    robot.h \
    viewwidget.h

DISTFILES += \
    test.txt \
    test2.txt
