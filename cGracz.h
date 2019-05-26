#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class cGracz :
	public Drawable
{
	RectangleShape shape_;
	const float gracz_w_{ 40.0f }; // szerokosc gracza
	const float gracz_h_{ 80.0f }; // wysokosc gracza
	const float gracz_vel_{ 0.20f }; // predkosc gracza
	Vector2f velocity{ gracz_vel_,0.0f };

public:
	cGracz(float t_x, float t_y);
	~cGracz() = default;
	cGracz() = delete;
	void draw(RenderTarget& target, RenderStates state) const override;
	void update();
	Vector2f getPosition();
	float left();
	float right();
	float down();
	float up();
};

