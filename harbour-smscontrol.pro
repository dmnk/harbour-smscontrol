# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = harbour-smscontrol

CONFIG += sailfishapp

QT += sql

SOURCES += src/harbour-smscontrol.cpp \
    src/typemodel.cpp \
    src/typemanager.cpp \
    src/devicestorage.cpp \
    src/devicemodel.cpp \
    src/devicemanager.cpp \
    src/controllabletype.cpp \
    src/controllabledevice.cpp \
    src/configuredcontrollabledevice.cpp \
    src/actionmodel.cpp \
    src/actionmanager.cpp \
    src/action.cpp

OTHER_FILES += qml/harbour-smscontrol.qml \
    qml/cover/CoverPage.qml \
    rpm/harbour-smscontrol.spec \
    rpm/harbour-smscontrol.yaml \
    harbour-smscontrol.desktop \
    qml/pages/AboutPage.qml \
    qml/pages/MainPage.qml \
    qml/pages/DisclaimerPage.qml \
    qml/pages/DisclaimerDialoguePage.qml \
    qml/pages/AddOverviewPage.qml \
    qml/pages/AddDetailPage.qml \
    qml/pages/ActionPage.qml \
    qml/images/devices/11.png \
    qml/images/devices/10.png \
    qml/images/devices/9.png \
    qml/images/devices/8.png \
    qml/images/devices/7.png \
    qml/images/devices/6.png \
    qml/images/devices/5.png \
    qml/images/devices/4.png \
    qml/images/devices/3.png \
    qml/images/devices/2.png \
    qml/images/devices/1.png \
    qml/images/actions/7.png \
    qml/images/actions/6.png \
    qml/images/actions/5.png \
    qml/images/actions/4.png \
    qml/images/actions/3.png \
    qml/images/actions/2.png \
    qml/images/actions/1.png \
    qml/images/devices/14.png \
    qml/images/devices/13.png \
    qml/images/harbour-smscontrol.png

HEADERS += \
    src/typemodel.h \
    src/typemanager.h \
    src/devicestorage.h \
    src/devicemodel.h \
    src/devicemanager.h \
    src/controllabletype.h \
    src/controllabledevice.h \
    src/Connection.h \
    src/configuredcontrollabledevice.h \
    src/actionmodel.h \
    src/actionmanager.h \
    src/action.h

