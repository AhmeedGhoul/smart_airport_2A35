QT       += core sql printsupport multimedia multimediawidgets charts svg network axcontainer widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app

DESTDIR = ../bin
CONFIG += c++11
CONFIG -= gui

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admins.cpp \
    avion.cpp \
    connection.cpp \
    historique.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    passager.cpp \
    pilote.cpp \
    pilotee.cpp \
    piste.cpp \
    qrcode.cpp \
    reservation.cpp \
    smtp.cpp \
    vol.cpp

HEADERS += \
    admins.h \
    avion.h \
    connection.h \
    historique.h \
    login.h \
    mainwindow.h \
    notification.h \
    passager.h \
    pilote.h \
    pilotee.h \
    piste.h \
    qrcode.h \
    reservation.h \
    smtp.h \
    vol.h \
    webaxwidget.h

FORMS += \
    login.ui \
    mainwindow.ui \
    pilotee.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
