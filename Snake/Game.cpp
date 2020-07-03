#include "Game.h"

Game::Game() :	videoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
				window(videoMode, WINDOW_TITLE, sf::Style::Default),
				running(false),
				timeSinceUpdate(0)
{
	snake.push_back(new SnakeObject(0, 0, TILE_SIZE, 1, 0));
	srand(time(NULL));
	generateNewPellet();
}

Game::~Game()
{

}

void Game::start()
{
	running = true;

	gameloop();
}

void Game::stop()
{
	running = false;
}

void Game::gameloop()
{
	sf::Clock _clock;
	window.setFramerateLimit(60);

	while (running)
	{
		getInput();
		update(_clock.restart().asSeconds());
		render();
	}
}

void Game::getInput()
{
	SnakeObject* _head = *snake.begin();

	sf::Event _event;
	while (window.pollEvent(_event))
	{
		if (_event.type == sf::Event::KeyPressed)
		{
			if (_event.key.code == sf::Keyboard::Up || _event.key.code == sf::Keyboard::W)
			{
				_head->setDeltaX(0);
				_head->setDeltaY(-1);
			}
			else if (_event.key.code == sf::Keyboard::Down || _event.key.code == sf::Keyboard::S)
			{
				_head->setDeltaX(0);
				_head->setDeltaY(1);
			}
			else if (_event.key.code == sf::Keyboard::Left || _event.key.code == sf::Keyboard::A)
			{
				_head->setDeltaX(-1);
				_head->setDeltaY(0);
			}
			else if (_event.key.code == sf::Keyboard::Right || _event.key.code == sf::Keyboard::D)
			{
				_head->setDeltaX(1);
				_head->setDeltaY(0);
			}
		}

		if (_event.type == sf::Event::Closed) running = false;
	}
}

void Game::update(float _deltaTime)
{
	timeSinceUpdate += _deltaTime;

	if (timeSinceUpdate >= UPDATE_DELAY)
	{
		SnakeObject* _head = *snake.begin();
		SnakeObject* _tail = *(snake.end() - 1);
		SnakeObject* _cur = NULL;

		int _prevDX = _head->getDeltaX();
		int _prevDY = _head->getDeltaY();
		int _nextDX, _nextDY;

		_head->update(_deltaTime);

		for (auto _it = snake.begin() + 1; _it != snake.end(); ++_it)
		{
			_cur = *_it;
			_cur->update(_deltaTime);
			
			_nextDX = _cur->getDeltaX();
			_nextDY = _cur->getDeltaY();

			_cur->setDeltaX(_prevDX);
			_cur->setDeltaY(_prevDY);

			_prevDX = _nextDX;
			_prevDY = _nextDY;
		}

		if (_head->getX() == pellet->getX() && _head->getY() == pellet->getY())
		{
			snake.push_back(new SnakeObject(_tail->getX(), _tail->getY(), TILE_SIZE));
			generateNewPellet();
		}

		timeSinceUpdate = 0.0;
	}
}

void Game::render()
{
	window.clear(sf::Color::Black);

	SnakeObject* _object;
	for (auto _it = snake.begin(); _it != snake.end(); ++_it)
	{
		_object = *_it;
		_object->render(window);
	}

	pellet->render(window);

	window.display();
}

void Game::generateNewPellet()
{
	delete pellet;

	int _x = rand() % BOARD_WIDTH;
	int _y = rand() % BOARD_HEIGHT;
	
	pellet = new Pellet(_x, _y, TILE_SIZE);
}