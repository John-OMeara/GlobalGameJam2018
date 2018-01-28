// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

#include "World.h"
#include "Camera.h"
#include "Menu.h"
#include "Cursor.h"
#include "Building.h"
#include "House.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	Camera m_camera;
	World m_world;
	Menu m_menu;
	Cursor m_cursor;

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game
};

#endif // !GAME

