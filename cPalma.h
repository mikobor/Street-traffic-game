#pragma once
#include <iostream>
//using namespace sf;
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;
class cPalma :
	public sf::Drawable
{

	Sprite palma1_;
	Sprite palma2_;
	Texture tex_palm1_;
	Texture tex_palm2_;
	int palm1_x_ = 00;
	int palm1_y_ = 00;
	int palm2_x_ = 700;
	int palm2_y_ = 00;
	float palm_vel_{ 10.10f };
	Vector2f palm_velocity_{0, palm_vel_};

	virtual void draw(RenderTarget& target, RenderStates states) const override;

public:
	void update();
	//void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	Vector2f getPosition1();
	Vector2f getPosition2();

	cPalma();
	~cPalma()=default;

};

