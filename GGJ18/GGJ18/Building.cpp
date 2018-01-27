#include "Building.h"


/// <summary>
/// Default constructor
/// </summary>
Building::Building(sf::Texture t, sf::Vector2f p):
	m_texture(t),
	m_position(p)
{
	
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
	//window.draw(m_sprite);
}
