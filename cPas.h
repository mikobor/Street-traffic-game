#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class cPas :
	public Drawable
{
	RectangleShape pas1_;
	RectangleShape pas2_;
	const float pas_w{ 10.0f };
	const float pas_h{ 80.0f };
	float pas_vel_{ 10.1f };
	Vector2f pas_velocity_{ 0, pas_vel_ };

	 void draw(RenderTarget& target, RenderStates states) const override;

public:
	void update();
	Vector2f getPosition1();
	Vector2f getPosition2();
	
	cPas(float p_y);
	~cPas()=default;
	

};

