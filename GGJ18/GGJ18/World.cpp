#include "World.h"

World::World() :
	m_houseCount(10)
{
	//Load image tild for texture
	if (!house_tex.loadFromFile(".\\ASSETS\\IMAGES\\House.png"))
	{
		//Error message for file loading failure
		std::cout << "ERROR: Failed to load file: " << __FILE__ << " at line : " << __LINE__ << std::endl;
	}

	init();
}

void World::init()
{
	for (int i = 0; i < m_houseCount; i++)
	{
		houses.push_back(new House(house_tex, sf::Vector2f(rand() % 800, rand() % 500)));
	}
}

void World::update()
{
}

void World::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < m_houseCount; i++)
	{
		houses.at(i)->draw(window);
	}
}
