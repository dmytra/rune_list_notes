QT     += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = rune_list_notes12
TEMPLATE = app

CONFIG += mobility  #https://github.com/qtproject/qt-mobility
MOBILITY = systeminfo #https://doc-snapshots.qt.io/qt-mobility/quickstart-quickstart-pro.html


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp\
    database.cpp \
    tablemodel.cpp

HEADERS += \
    mainwindow.h \
    database.h \
    tablemodel.h

FORMS += \
    mainwindow.ui
    # file mainwindow 2.ui - remove two page + page_2

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}


