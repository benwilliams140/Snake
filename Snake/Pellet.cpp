#include "Pellet.h"

Pellet::Pellet(int _x, int _y, int _size) : x(_x), y(_y), size(_size)
{

}

Pellet::~Pellet()
{

}

void Pellet::render(sf::RenderWindow& _window)
{
	sf::CircleShape _circ;
	_circ.setRadius(size / 4);
	_circ.setOrigin(sf::Vector2f(_circ.getRadius(), _circ.getRadius()));
	_circ.setPosition(sf::Vector2f(x * size + size / 2, y * size + size / 2));
	_circ.setFillColor(sf::Color::White);

	_window.draw(_circ);
}

int Pellet::getX() { return x; }

int Pellet::getY() { return y; }