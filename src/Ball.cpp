#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"

Ball::Ball(sf::CircleShape *shape, float x, float y, float r, float dx, float dy, sf::Color *color) {
	_x = x;
	_y = y;
	_r = r;
	_dx = dx;
	_dy = dy;
	_cs = shape;
	_color = color;

	(*_cs).setFillColor(*_color);
};

Ball::Ball(sf::CircleShape *shape, float x, float y, float r, float dx, float dy) {
	_x = x;
	_y = y;
	_r = r;
	_dx = dx;
	_dy = dy;
	_cs = shape;
};

//Destructor for the Ball
Ball::~Ball() {
	delete _cs;//Deletes the sf::CS object
	if (_color != NULL)
		delete _color;
}

void Ball::tick() {
	//Checks for collision against the walls
	if (_x <= 0 || _x >= 600 - _r) {
		_dx = -_dx;
	}
	if (_y <= 0 || _y >= 600 - _r) {
		_dy = -_dy;
	}

	//Sets the sf::cs's position to x + velX and y + velY
	(*_cs).setPosition(_x += _dx, _y += _dy);

	unsigned short r = _x / 600 * 0xFF; //The red value dependent on its x value

	//Clamps the r value to 255 if it's above
	if (r > 255)
		r = 255;
	//Sets the color 
	(*_cs).setFillColor(sf::Color(r, 0, 0xFF, 0xFF));
}

float Ball::getX() {
	return _x;
}

float Ball::getY() {
	return _y;
}

float Ball::getVelX() {
	return _dx;
}

float Ball::getVelY() {
	return _dy;
}

float Ball::getRadius() {
	return _r;
}

sf::CircleShape Ball::getShape() {
	return *_cs;
}

