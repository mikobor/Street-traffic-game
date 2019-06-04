#include "cGracz.h"


/*
cGracz::cGracz(float t_x, float t_y)
{
	shape_.setPosition(t_x, t_y);
	shape_.setSize({ this->gracz_w_,this->gracz_h_ });
	shape_.setFillColor(Color::Green);
	shape_.setOrigin(gracz_w_ / 2.f, gracz_h_ / 2.f);

}
void cGracz::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_, state);
}

void cGracz::update()
{
	this->shape_.move(this->velocity);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
		velocity.x = -gracz_vel_;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
		velocity.x = gracz_vel_;
	else
		velocity.x = 0.0;
}

float cGracz::left()
{
	return this->shape_.getPosition().x - shape_.getSize().x / 2.f;
}

float cGracz::right()
{
	return this->shape_.getPosition().x + shape_.getSize().x / 2.f;
}

Vector2f cGracz::getPosition()
{
	return shape_.getPosition();
}

float cGracz::down()
{
	return this->shape_.getPosition().y + shape_.getSize().y / 2.f;
}

float cGracz::up()
{
	return this->shape_.getPosition().y - shape_.getSize().y / 2.f;
}*/