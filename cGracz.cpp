#include "cGracz.h"



cGracz::cGracz(float t_x, float t_y)
{

    tex_gracz.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/taxi5.png");

	gracz_.setPosition(t_x, t_y);
    gracz_.setTexture(tex_gracz);
    gracz_.setScale(0.5, 0.35f);
    gracz_.setOrigin(73.5,110.6f);
    hp3.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/hp.png");
    hp2.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/hp2.png");
    hp1.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/hp1.png");
    hp0.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/hp0.png");
    gmo.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/gameover.png");
    healthPoint_.setTexture(hp3);
    healthPoint_.setPosition(5,5);
    end.setPosition(280,220);
    font.loadFromFile("D:/Projekty QT++/build-STG_test-Desktop_Qt_5_12_3_MSVC2017_32bit-Debug/debug/font.otf");
    score_.setFont(font);
    score_.setCharacterSize(20);
    score_.setOutlineThickness(2);
    score_.setString(L"0");
    score_.setPosition(680,5);
    score_.setFillColor(Color::White);
    score_.setOutlineColor(Color::Black);


}
void cGracz::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->gracz_, state);
    target.draw(this->healthPoint_,state);
    target.draw(this->score_,state);
    target.draw(this->end,state);

}

int cGracz::update()
{
    if(hp_==2)
    {
        healthPoint_.setTexture(hp2);
    }
    if(hp_==1)
        healthPoint_.setTexture(hp1);
    if(hp_<=0)
    {
        end.setTexture(gmo);
        healthPoint_.setTexture(hp0);
        return 0;
    }

    gracz_vel_ = gracz_vel_+0.002f;

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
