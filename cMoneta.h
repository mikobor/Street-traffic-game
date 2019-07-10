#pragma once
#include "cGracz.h"
#include "cPrzeszkoda.h"
#include <SFML\Graphics.hpp>

using namespace sf;

class cMoneta :
    public Drawable
{
    Sprite moneta_;
    Texture moneta1_tex;
    Texture moneta2_tex;
    float moneta_vel{ 10.10f };
    Vector2f moneta_velocity_{ 0,moneta_vel };
    int score_{300};


    virtual void draw(RenderTarget& target, RenderStates states) const override;
public:
    cMoneta();


    void update(cPrzeszkoda &przeszkoda,cGracz &gracz);
    ~cMoneta()override=default ;

};

