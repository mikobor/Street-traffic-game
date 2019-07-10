#include "cPalma.h"



cPalma::cPalma(float p_y)
{

    tex_palm1_.loadFromFile("Resources/palma1.png");
    palma1_.setTexture(tex_palm1_);
    palma1_.setScale(1, 1.4f);
    palma1_.setPosition(0,p_y);

    tex_palm2_.loadFromFile("Resources/palma2.png");
    palma2_.setTexture(tex_palm2_);
    palma2_.setScale(1, 1.4f);
    palma2_.setPosition(700,p_y);

}

void cPalma::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->palma1_, state);
    target.draw(this->palma2_, state);
}

void cPalma::update( cGracz &gracz)
{
    palm_vel_ = palm_vel_+0.0008f;
    palm_velocity_={0,palm_vel_};

    if(gracz.getHp()<=0)
        this->palm_vel_=0;

    this->palma1_.move(this->palm_velocity_);
    this->palma2_.move(this->palm_velocity_);

    if (this->palma1_.getPosition().y > 800)
        this->palma1_.setPosition(0, -100);

    if (this->palma2_.getPosition().y > 800)
        this->palma2_.setPosition(700, -100);


}

