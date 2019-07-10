#pragma once
#include <iostream>
#include "cGracz.h"
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;
class cPalma :
    public sf::Drawable
{
    Sprite palma1_;
    Sprite palma2_;
    Texture tex_palm1_;
    Texture tex_palm2_;
    float palm_vel_{ 10.80f };
    Vector2f palm_velocity_{0.0f, palm_vel_};
    void draw(RenderTarget& target, RenderStates states) const override;

public:
    void update( cGracz &gracz);



    cPalma(float p_y);
    ~cPalma()override=default;

};

