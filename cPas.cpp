#include "cPas.h"



cPas::cPas(float p_y)
{
															//		ustawienie pasow na jezdni
	pas1_.setFillColor(Color::White);
    pas1_.setSize({ 10 , 80 });//this->pas_w,this->pas_h });
	pas1_.setPosition(300,p_y);
    //pas1_.setOrigin({ this->pas_w / 2,this->pas_h / 2 });
														
	pas2_.setFillColor(Color::White);
    pas2_.setSize({ 10 , 80 });//this->pas_w,this->pas_h });
	pas2_.setPosition(500,p_y);
    //pas2_.setOrigin({ this->pas_w / 2,this->pas_h / 2 });

}

void cPas::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->pas1_, state);
	target.draw(this->pas2_, state);
}

void cPas::update(cGracz &gracz)
{ 
    this->pas_vel_ = pas_vel_+0.002f;

    if(gracz.getHp()<=0)
        this->pas_vel_=0;

    this->pas1_.move(this->pas_velocity_);
    this->pas2_.move(this-> pas_velocity_);

    if (this->pas1_.getPosition().y > 800)
        this->pas1_.setPosition(300, -200);

    if (this->pas2_.getPosition().y > 800)
        this->pas2_.setPosition(500, -200);



}

