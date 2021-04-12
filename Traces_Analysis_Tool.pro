TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += \
        atom.cpp \
        experiment.cpp \
        interface2.cpp \
        main.cpp \
        mainwindow.cpp \
        robot.cpp \
        robotwidget.cpp \
        viewwidget.cpp

HEADERS += \
    atom.h \
    experiment.h \
    interface2.h \
    mainwindow.h \
    robot.h \
    robotwidget.h \
    viewwidget.h

DISTFILES += \
    test.txt \
    test2.txt

FORMS += \
    interface2.ui \
    robotwidget.ui
