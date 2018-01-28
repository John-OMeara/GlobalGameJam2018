#ifndef WORLD_H
#define WORLD_H

#include <cstdlib>
#include <SFML\Graphics.hpp>
#include "House.h"
#include "NPC.h"

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
	int m_npcCount;

	std::vector<House * > houses;
	sf::Texture house_tex;

	std::vector<NPC*> m_npcs;
	sf::Texture m_npcTexture;
};

#endif // !WORLD_H
