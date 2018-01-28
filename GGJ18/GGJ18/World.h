#ifndef WORLD_H
#define WORLD_H

#include <cstdlib>
#include <SFML\Graphics.hpp>
#include "House.h"

class World
{
public:
	World();

	void init();
	
	void update();
	void draw(sf::RenderWindow &window);

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	int m_houseCount;

	std::vector<House * > houses;
	sf::Texture house_tex;
};

#endif // !WORLD_H
