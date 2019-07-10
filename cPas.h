#pragma once
#include <SFML\Graphics.hpp>
#include "cGracz.h"

using namespace sf;

class cPas :
    public Drawable
{
    RectangleShape pas1_;
    RectangleShape pas2_;
    float pas_vel_{ 10.80f };
    Vector2f pas_velocity_{ 0, pas_vel_ };
    int pasy_{ 0 };

    void draw(RenderTarget& target, RenderStates states) const override;

public:
    void update(cGracz &gracz);
    cPas(float p_y);
    ~cPas() override=default;


};

