#include "cPalma.h"



cPalma::cPalma(float p_y)
{
												//       ustawienie palm na bokach mapy
	tex_palm1_.loadFromFile("palma1.png");
	palma1_.setTexture(tex_palm1_);
	palma1_.setScale(1, 1.4);
	palma1_.setPosition(0,p_y-100);
	
	tex_palm2_.loadFromFile("palma2.png");
	palma2_.setTexture(tex_palm2_);
	palma2_.setScale(1, 1.4);
	palma2_.setPosition(700,p_y);
	
}

void cPalma::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->palma1_, state);
	target.draw(this->palma2_, state);
}

void cPalma::update()
{
	palma1_.move(palm_velocity_);
	palma2_.move(palm_velocity_);
	if (palma1_.getPosition().y > 800)
		palma1_.setPosition(-0, -700);
	if (palma2_.getPosition().y > 800)
		palma2_.setPosition(700, -700);
}

Vector2f cPalma::getPosition1()
{
	return palma1_.getPosition();
}

Vector2f cPalma::getPosition2()
{
	return palma2_.getPosition();
}

