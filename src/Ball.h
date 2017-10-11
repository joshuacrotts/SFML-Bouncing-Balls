#include <SFML/Graphics.hpp>
#pragma once
#define Ball_h


class Ball {
private:
	float _x, _y, _r, _dx, _dy;
	sf::CircleShape *_cs;
	sf::Color *_color;
public:
	Ball(sf::CircleShape *cs, float x, float y, float r, float dx, float dy, sf::Color *color);
	Ball(sf::CircleShape *cs, float x, float y, float r, float dx, float dy);
	~Ball();

	void tick();
	float getX();
	float getY();
	float getRadius();
	float getVelX();
	float getVelY();

	sf::CircleShape getShape();

};