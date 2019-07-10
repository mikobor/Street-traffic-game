#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "cGracz.h"
using namespace sf;
using namespace std;

class cPrzeszkoda :
    public Drawable
{
    virtual void draw(RenderTarget& target, RenderStates states) const override;
    Sprite auto3_;
    Sprite auto1_;
    Sprite auto2_;
    Texture taxi_tex;
    Texture auto_tex;
    Texture pickup_tex;
    float przeszkoda_vel{ 10.10f };
    Vector2f przeszkoda_velocity_{ 0,przeszkoda_vel };
    int losowosc;
    bool destroyed_=false;
    Sound trach;
    SoundBuffer trach_buffer;
public:
    cPrzeszkoda( float t_y);
    void update( cGracz &gracz);
    FloatRect getGlobalBounds1();
    FloatRect getGlobalBounds2();
    FloatRect getGlobalBounds3();
    ~cPrzeszkoda()override=default;

};

