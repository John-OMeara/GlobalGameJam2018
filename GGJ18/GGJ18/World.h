#ifndef WORLD_H
#define WORLD_H

#include <SFML\Graphics.hpp>

class World
{
public:
	World();

	void init();
	
	void update();
	void draw();

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};

#endif // !WORLD_H
