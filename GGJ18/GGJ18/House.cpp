#include "House.h"

/// <summary>
/// 
/// </summary>
House::House(sf::Texture t, sf::Vector2f p):
	Building(t,p)
{

}

/// <summary>
/// 
/// </summary>
House::~House()
{
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Vector2f House::getPosition()
{
	return m_position;
}
