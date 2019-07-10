#include "cGracz.h"



cGracz::cGracz(float t_x, float t_y)
{

    tex_gracz.loadFromFile("Resources/taxi5.png");
    font.loadFromFile("Resources/font.otf");
    gracz_.setPosition(t_x, t_y);
    gracz_.setTexture(tex_gracz);
    gracz_.setScale(0.5, 0.35f);
    gracz_.setOrigin(73.5,110.6f);
    hp3.loadFromFile("Resources/hp.png");
    hp2.loadFromFile("Resources/hp2.png");
    hp1.loadFromFile("Resources/hp1.png");
    healthPoint_.setTexture(hp3);
    healthPoint_.setPosition(5,5);
    score_.setFont(font);
    score_.setCharacterSize(20);
    score_.setOutlineThickness(2);
    score_.setString("0");
    score_.setPosition(680,5);
    score_.setFillColor(Color::White);
    score_.setOutlineColor(Color::Black);
}
void cGracz::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->gracz_, state);
    target.draw(this->healthPoint_,state);
    target.draw(this->score_,state);
}

void cGracz::update()
{
    if(hp_==2)
        healthPoint_.setTexture(hp2);

    if(hp_==1)
        healthPoint_.setTexture(hp1);

    gracz_vel_ = gracz_vel_+0.0003f;

    this->gracz_.move(this->velocity);

    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->gracz_.getPosition().x > 145)
        velocity.x = -gracz_vel_;
    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->gracz_.getPosition().x < 570)
        velocity.x = gracz_vel_;
    else
        velocity.x = 0.0;

    score++;
    sco="Score: "+std::to_string(score/6);
    score_.setString(sco);

}

void cGracz::setHp(int hp)
{
    hp_=hp;
}

int cGracz::getHp()
{
    return hp_;
}

void cGracz::setScore(int score1)
{
    this->score=score1;
}

int cGracz::getScore()
{
    return this->score;
}

FloatRect cGracz::getGlobalBounds()
{
    return gracz_.getGlobalBounds();
}
