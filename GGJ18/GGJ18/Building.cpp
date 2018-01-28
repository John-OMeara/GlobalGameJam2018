#include "Building.h"


/// <summary>
/// Default constructor
/// </summary>
Building::Building(sf::Texture t, sf::Vector2f p):
	m_texture(t),
	m_position(p)
{
	m_sprite.setPosition(m_position);
	m_sprite.setTexture(m_texture);
}

/// <summary>
/// Deconstructor
/// </summary>
Building::~Building()
{

}
 
/// <summary>
/// 
/// </summary>
void Building::update()
{
	std::cout << "Super class update" << std::endl;
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void Building::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

/// <summary>
/// Checks if a position is within the bounds
/// of a building
/// </summary>
/// <param name="p"></param>
/// <param name="r"></param>
/// <returns></returns>
bool Building::withinRadius(sf::Vector2f p)
{
	//Check if position is within 5px of the building position
	if (this->m_position.x > p.x - 5 && this->m_position.x < p.x + 5
		&& this->m_position.y > p.y - 5 && this->m_position.y < p.y + 5)
	{
		//If it is, then return function as true
		return true;
	}

	//Otherwise return false
	return false;
}

/// <summary>
/// Returns the position of the building
/// or subclass object
/// </summary>
/// <returns></returns>
sf::Vector2f Building::getPosition()
{
	return m_position;
}
