#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class cGracz :
    public Drawable
{
    Sprite gracz_;
    Texture tex_gracz;
    Sprite healthPoint_;
    Texture hp3;
    Texture hp2;
    Texture hp1;
    Text score_;
    String sco;
    Font font;
    float gracz_vel_{ 8.50f };
    Vector2f velocity{ gracz_vel_,0.0f };
    virtual void draw(RenderTarget& target, RenderStates states) const override;
    int hp_{ 3 };
    int score{ 0 };

public:
    cGracz(float t_x, float t_y);
    ~cGracz() override = default;
    void update();
    void setHp(int hp);
    int getHp();
    void setScore(int score1);
    int getScore();
    FloatRect getGlobalBounds();

};

