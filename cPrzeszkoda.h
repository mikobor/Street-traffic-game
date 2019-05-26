#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class cPrzeszkoda :
	public Drawable
{
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	RectangleShape shape_;
	bool destroyed();
public:
	cPrzeszkoda(float t_x, float t_y, float t_width, float t_height);
	void draw(RenderTarget& target, RenderStates state) const override;
	void update();
	Vector2f getPosition();
	float left();
	float right();
	float bottom();
	float top();
	bool isDestroyed();
	void destroy();
	Vector2f getSize();
	~cPrzeszkoda() = default;
	cPrzeszkoda() = delete;
};

