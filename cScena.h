#pragma once

#include <iostream>
#include "cPalma.h"
#include "cPas.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>
#include "cGracz.h"
#include "cPrzeszkoda.h"
#include "cMoneta.h"
#include "cMenu.h"
#include "chighscore.h"

class cScena
{
    RenderWindow *okno;
    Event zdarzenie;
    Sprite background;
    Texture startpage_tex;
    Texture menu_tex;
    Texture map_tex;
    Texture highscore_tex;
    Texture nick_tex;
    Font font;
    int licznik=1;
    string nick;
    Text nick_;
    cMenu menu;
    cGracz* gracz;
    vector<cPalma*> palmy;
    vector<cPas*> pasy;
    cMoneta* moneta;
    cPrzeszkoda* przeszkoda;
    cHighscore highscore;
    Sound soundtrack;
    SoundBuffer soundtrack_buff;
    bool menuSt=true;
    bool gameSt=false;
    bool highscoreSt=false;
    bool nickSt=false;



    void initOkno();

public:
    cScena();
    ~cScena();
    void zdarzeniaUpdate();//Event zdarzenie);
    void update();
    void render();
    void run();
    bool oknoisOpen();
};


