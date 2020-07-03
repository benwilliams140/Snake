#ifndef PELLET_H
#define PELLET_H

#include <SFML/Graphics.hpp>

class Pellet
{
public:
	Pellet(int, int, int);
	~Pellet();

	void render(sf::RenderWindow&);

	int getX();
	int getY();

private:
	int x, y, size;
};

#endif