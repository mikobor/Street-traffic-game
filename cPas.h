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
	int pas1_x_ = 300;
	int pas1_y_ = 0;
	int pas2_x_ = 500;
	int pas2_y_ = 0;
	float pas_vel_{ 15.10f };
	Vector2f pas_velocity_{ 0, pas_vel_ };

	virtual void draw(RenderTarget& target, RenderStates states) const override;

public:
	void update();
	//void draw(RenderTarget& target, RenderStates state) const override;
	Vector2f getPosition1();
	Vector2f getPosition2();
	
	cPas();
	~cPas()=default;
	

};

