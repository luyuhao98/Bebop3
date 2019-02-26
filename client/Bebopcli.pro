#-------------------------------------------------
#
# Project created by QtCreator 2018-12-12T23:29:52
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bebopclient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwin.cpp \
    loginui.cpp \
    signupui.cpp \
    userinfo.cpp \
    pagelet.cpp \
    board.cpp \
    client.cpp \
    post.cpp \
    tabui.cpp \
    homepageui.cpp \
    hpmainui.cpp \
    pageui.cpp \
    postui.cpp \
    commentpostui.cpp \
    usrlistui.cpp \
    usrlistmainui.cpp \
    promotebm.cpp \
    settingui.cpp

HEADERS += \
        mainwin.h \
    loginui.h \
    signupui.h \
    userinfo.h \
    pagelet.h \
    board.h \
    client.h \
    post.h \
    tabui.h \
    homepageui.h \
    hpmainui.h \
    pageui.h \
    postui.h \
    commentpostui.h \
    usrlistui.h \
    usrlistmainui.h \
    promotebm.h \
    settingui.h

FORMS += \
        mainwin.ui \
    loginui.ui \
    signupui.ui \
    tabui.ui \
    hpmainui.ui \
    postui.ui \
    commentpostui.ui \
    usrlistmainui.ui \
    promotebm.ui \
    settingui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES +=
