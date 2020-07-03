#include "SnakeObject.h"

SnakeObject::SnakeObject(int _x, int _y, int _size, int _deltaX, int _deltaY)
	: x(_x), y(_y), size(_size), deltaX(_deltaX), deltaY(_deltaY)
{
}

SnakeObject::~SnakeObject()
{

}

bool SnakeObject::update(float _deltaTime)
{
	x += deltaX;
	y += deltaY;

	if (x >= 0 && x < 20)
		if (y >= 0 && y < 20)
			return true;

	return false;
}

void SnakeObject::render(sf::RenderWindow& _window)
{
	sf::RectangleShape _rect;
	_rect.setOrigin(0, 0);
	_rect.setSize(sf::Vector2f(size, size));
	_rect.setPosition(sf::Vector2f(x * size, y * size));
	_rect.setFillColor(sf::Color::White);
	_window.draw(_rect);
}

int SnakeObject::getX() { return x; }

int SnakeObject::getY() { return y; }

int SnakeObject::getDeltaX() { return deltaX; }

int SnakeObject::getDeltaY() { return deltaY; }

void SnakeObject::setDeltaX(int _x) { deltaX = _x; }

void SnakeObject::setDeltaY(int _y) { deltaY = _y; }