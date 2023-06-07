QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    brayan.cpp \
    character.cpp \
    cinematic.cpp \
    control_sprite.cpp \
    game.cpp \
    game_over.cpp \
    main.cpp \
    mainwindow.cpp \
    music.cpp \
    object.cpp \
    points.cpp \
    police.cpp \
    start_menu.cpp

HEADERS += \
    background.h \
    brayan.h \
    character.h \
    cinematic.h \
    control_sprite.h \
    game.h \
    game_over.h \
    global_macros.h \
    macros_vitales.h \
    mainwindow.h \
    music.h \
    object.h \
    points.h \
    police.h \
    start_menu.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
