#ifndef SNAKE_OBJECT_H
#define SNAKE_OBJECT_H

#include <SFML/Graphics.hpp>

class SnakeObject
{
public:
	SnakeObject(int, int, int, int = 0, int = 0);
	~SnakeObject();

	bool update(float);
	void render(sf::RenderWindow&);

	int getX();
	int getY();
	int getDeltaX();
	int getDeltaY();

	void setDeltaX(int);
	void setDeltaY(int);

private:
	int x, y, deltaX, deltaY, size;
};

#endif