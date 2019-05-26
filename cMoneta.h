#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class cMoneta :
	public Drawable
{
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	CircleShape shape_;
	bool destroyed();
public:
	cMoneta(float t_x, float t_y, float t_width, float t_height);
	
	void draw(RenderTarget& target, RenderStates state) const override;
	void update();
	Vector2f getPosition();
	float left();
	float right();
	float bottom();
	float top();
	bool isDestroyed();
	void destroy();
	~cMoneta() = default;
	cMoneta() = delete;
};

