QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editor.cpp \
    editorbutton.cpp \
    highlighter.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowslots.cpp \
    fscdocument.cpp \
    fscobject.cpp \
    whighlightpreferences.cpp

HEADERS += \
    editor.h \
    editorbutton.h \
    highlighter.h \
    mainwindow.h \
    style_sheets.h \
    fscdocument.h \
    fscobject.h \
    whighlightpreferences.h

FORMS += \
    mainwindow.ui \
    whighlightpreferences.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
