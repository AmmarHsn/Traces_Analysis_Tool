TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += \
        atom.cpp \
        colorwidget.cpp \
        experiment.cpp \
        interface2.cpp \
        main.cpp \
        mainwindow.cpp \
        mypushboutton.cpp \
        robot.cpp \
        robotinfowidget.cpp \
        robotwidget.cpp \
        viewwidget.cpp \
        zoom.cpp

HEADERS += \
    atom.h \
    colorwidget.h \
    experiment.h \
    interface2.h \
    mainwindow.h \
    mypushboutton.h \
    robot.h \
    robotinfowidget.h \
    robotwidget.h \
    viewwidget.h \
    zoom.h

DISTFILES += \
    test.txt \
    test2.txt

FORMS += \
    colorwidget.ui \
    interface2.ui \
    robotwidget.ui \
    zoom.ui
