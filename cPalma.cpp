#include "cPalma.h"



cPalma::cPalma()
{
												//       ustawienie palm na bokach mapy
	tex_palm1_.loadFromFile("palma1.png");
	palma1_.setTexture(tex_palm1_);
	palma1_.setScale(1, 1.4);
	palma1_.setPosition(palm1_x_,palm1_y_);
	
	tex_palm2_.loadFromFile("palma2.png");
	palma2_.setTexture(tex_palm2_);
	palma2_.setScale(1, 1.4);
	palma2_.setPosition(palm2_x_, palm2_y_);

}

void cPalma::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->palma1_, state);
	target.draw(this->palma2_, state);
}

void cPalma::update()
{

	palma1_.setPosition(this->getPosition1() + palm_velocity_);
	palma2_.setPosition(this->getPosition2() + palm_velocity_);
}

Vector2f cPalma::getPosition1()
{
	return palma1_.getPosition();
}

Vector2f cPalma::getPosition2()
{
	return palma2_.getPosition();
}