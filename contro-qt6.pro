QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Qt6Keychain support
LIBS += -lqt6keychain
INCLUDEPATH += /usr/include/qt6keychain
DEPENDPATH += /usr/include/qt6keychain

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/core/pocketbaseclient.cpp \
    src/ui/contractdialog.cpp \
    src/core/sessionmanager.cpp \
    src/ui/entidaddialog.cpp

HEADERS += \
    src/ui/mainwindow.h \
    src/core/pocketbaseclient.h \
    src/ui/contractdialog.h \
    src/core/sessionmanager.h \
    src/ui/entidaddialog.h

FORMS += \
    src/ui/mainwindow.ui \
    src/ui/contractdialog.ui \
    src/ui/entidaddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
