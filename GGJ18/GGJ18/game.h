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
#include "NPC.h"

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
	NPC m_npc;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	std::vector<House * > houses;
	sf::Texture house_tex;
	sf::Texture hosp_tex;
	sf::Texture tav_tex;

	void processEvents();
	void loadFiles();
	
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game
};

#endif // !GAME

