#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T11:05:08
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = control_android
TEMPLATE = app

SOURCES += \
    main.cpp \
    MxRemoteIp.cpp \
    MxSQLManage.cpp \
    MxMainInterface.cpp \
    MxLoginDialog.cpp


HEADERS  += \
    MxRemoteIp.h \
    MxSQLManage.h \
    MxLoginDialog.h \
    MxMainInterface.h

win32 {
HEADERS +=qrcode/qrcodegenerate.h
SOURCES +=qrcode/qrcodegenerate.cpp
}
win32:LIBS +=-LD:/sourcetreedown/chinagit/VenipunctureMobileClient/lib64 -lqrcodelib

FORMS    += \
    login.ui \
    widget.ui

CONFIG += mobility c++11
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

RESOURCES += \
    rec.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

