// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

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
	Menu m_menu;
	Cursor m_cursor;
	std::vector<House * > houses;
	sf::Texture house_tex;
	sf::Texture hosp_tex;
	sf::Texture tav_tex;

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void loadFiles();
	
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window

	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo

	bool m_exitGame; // control exiting game
};

#endif // !GAME

