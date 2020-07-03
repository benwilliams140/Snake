#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "SnakeObject.h"
#include "Pellet.h"

const unsigned int BOARD_WIDTH = 20;
const unsigned int BOARD_HEIGHT = 20;
const unsigned int TILE_SIZE = 20;

const unsigned int WINDOW_WIDTH = BOARD_WIDTH * TILE_SIZE;
const unsigned int WINDOW_HEIGHT = BOARD_HEIGHT * TILE_SIZE;
const sf::String WINDOW_TITLE = "Snake";

const float UPDATE_DELAY = 0.1;

class Game
{
public:
	Game();
	~Game();

	void start();
	void stop();

private:
	void gameloop();
	void getInput();
	void update(float);
	void render();
	void generateNewPellet();

	sf::VideoMode videoMode;
	sf::RenderWindow window;
	
	std::vector<SnakeObject*> snake;
	Pellet* pellet;

	bool running;
	float timeSinceUpdate;
};

#endif