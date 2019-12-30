#-------------------------------------------------
#
# Project created by QtCreator 2019-11-17T17:18:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stopwatch
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
    digitsw/btnbase.cpp \
    digitsw/btnblue.cpp \
    digitsw/btngreen.cpp \
    digitsw/btnred.cpp \
    digitsw/digframe.cpp \
    digitsw/digitled.cpp \
    digitsw/tblrecord.cpp \
    graphsw/__segmentbtn.cpp \
    graphsw/__swsegmt.cpp \
    graphsw/cmdbtn.cpp \
    graphsw/cmdbtnleft.cpp \
    graphsw/cmdbtnright.cpp \
    graphsw/stopwatchscene.cpp \
    graphsw/stopwatchview.cpp \
    graphsw/swatch.cpp \
    graphsw/swbtn.cpp \
    graphsw/swbtnleft.cpp \
    graphsw/swbtnright.cpp \
    graphsw/swclock.cpp \
    graphsw/swdial.cpp \
    graphsw/swstate.cpp \
    graphsw/swtimer.cpp \
        main.cpp \
    mainframe.cpp


HEADERS += \
    digitsw/btnbase.h \
    digitsw/btnblue.h \
    digitsw/btngreen.h \
    digitsw/btnred.h \
    digitsw/digframe.h \
    digitsw/digitled.h \
    digitsw/tblrecord.h \
    graphsw/__segmentbtn.h \
    graphsw/__swsegmt.h \
    graphsw/cmdbtn.h \
    graphsw/cmdbtnleft.h \
    graphsw/cmdbtnright.h \
    graphsw/global.h \
    graphsw/stopwatchscene.h \
    graphsw/stopwatchview.h \
    graphsw/swatch.h \
    graphsw/swbtn.h \
    graphsw/swbtnleft.h \
    graphsw/swbtnright.h \
    graphsw/swclock.h \
    graphsw/swdial.h \
    graphsw/swstate.h \
    graphsw/swtimer.h \
    mainframe.h \
    stopwatchview.h \
    stopwatchscene.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += graphsw/
INCLUDEPATH += digitsw/
RESOURCES +=

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}
