#include "cPas.h"



cPas::cPas()
{
															//		ustawienie pasow na jezdni
	pas1_.setFillColor(Color::White);
	pas1_.setSize({ this->pas_w,this->pas_h });
	pas1_.setPosition(pas1_x_,pas1_y_);
	pas1_.setOrigin({ this->pas_w / 2,this->pas_h / 2 });
														
	pas2_.setFillColor(Color::White);
	pas2_.setSize({ this->pas_w,this->pas_h });
	pas2_.setPosition(pas2_x_,pas2_y_);
	pas2_.setOrigin({ this->pas_w / 2,this->pas_h / 2 });

}

void cPas::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->pas1_, state);
	target.draw(this->pas2_, state);
}

void cPas::update()
{
	pas1_.setPosition(this->getPosition1() + pas_velocity_);
	pas2_.setPosition(this->getPosition2() + pas_velocity_);

}
Vector2f cPas::getPosition1()
{
	return pas1_.getPosition();
}

Vector2f cPas::getPosition2()
{
	return pas2_.getPosition();
}
