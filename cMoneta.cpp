#include "cMoneta.h"



cMoneta::cMoneta()
{
    moneta1_tex.loadFromFile("Resources/pigcoin.png");
    moneta2_tex.loadFromFile("Resources/Bitcoin.png");
    moneta_.setScale(0.2f,0.2f);
    moneta_.setPosition(-155,890);
    moneta_.setTexture(moneta1_tex);
}


void cMoneta::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(this->moneta_,states);
}

void cMoneta::update(cPrzeszkoda &przeszkoda, cGracz &gracz)
{
    if(gracz.getHp()<=0)
        this->moneta_vel=0;

    if((gracz.getScore())%1200==0)
    {


        switch (gracz.getScore()%3)
        {
        case 1:
            moneta_.setPosition(155,-155);
            break;
        case 2:
            moneta_.setPosition(355,-155);
            break;
        case 0:
            moneta_.setPosition(555,-155);
            break;
        }
    }

    this->moneta_vel=moneta_vel+0.0008f;
    moneta_velocity_={0,moneta_vel};

    if(moneta_.getPosition().y<=860)
        this->moneta_.move(this->moneta_velocity_);

    if(gracz.getGlobalBounds().intersects(this->moneta_.getGlobalBounds()))
    {
        gracz.setScore(gracz.getScore()+score_);
        moneta_.setPosition(0,860);
        switch (rand()%8)
        {
        case 0:
            moneta_.setTexture(moneta2_tex);
            score_=600;
            break;
        default:
            moneta_.setTexture(moneta1_tex);
            score_=300;
            break;
        }
    }
    if(moneta_.getPosition().y>=1060)
    {
        switch (rand()%8)
        {
        case 0:
            moneta_.setTexture(moneta2_tex);
            score_=600;
            break;
        default:
            moneta_.setTexture(moneta1_tex);
            score_=300;
            break;
        }
    }

    if(przeszkoda.getGlobalBounds1().intersects(this->moneta_.getGlobalBounds())||przeszkoda.getGlobalBounds2().intersects(this->moneta_.getGlobalBounds())||przeszkoda.getGlobalBounds3().intersects(this->moneta_.getGlobalBounds()))
        this->moneta_.setPosition(this->moneta_.getPosition().x,this->moneta_.getPosition().y-150);


}


