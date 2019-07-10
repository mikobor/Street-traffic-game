TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -LC:/Users/Borys/source/repos/_SFML/SFML-2.5.1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:/Users/Borys/source/repos/_SFML/SFML-2.5.1/include
DEPENDPATH += C:/Users/Borys/source/repos/_SFML/SFML-2.5.1/include

SOURCES += \
        cGracz.cpp \
        cMenu.cpp \
        cMoneta.cpp \
        cPalma.cpp \
        cPas.cpp \
        cPrzeszkoda.cpp \
        chighscore.cpp \
        main.cpp \
        main/main.cpp

HEADERS += \
    cGracz.h \
    cMenu.h \
    cMoneta.h \
    cPalma.h \
    cPas.h \
    cPrzeszkoda.h \
    chighscore.h

DISTFILES += \
    Resources/Bitcoin.png \
    Resources/Highscore.txt \
    Resources/Trach.wav \
    Resources/auto2.png \
    Resources/font.otf \
    Resources/highscore.png \
    Resources/hp.png \
    Resources/hp1.png \
    Resources/hp2.png \
    Resources/mapa.png \
    Resources/menu1.png \
    Resources/palma1.png \
    Resources/palma2.png \
    Resources/pickup.png \
    Resources/pigcoin.png \
    Resources/podaj_nick.png \
    Resources/soundtrack_only.wav \
    Resources/startpage.jpg \
    Resources/taxi5.png
