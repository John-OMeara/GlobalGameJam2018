#include "Building.h"


/// <summary>
/// Default constructor
/// </summary>
Building::Building(sf::Texture t, sf::Vector2f p):
	m_texture(t),
	m_position(p),
	isInfected(false)
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

	if (this->checkInfected())
	{
		if (m_occupants.size() != 0)
		{
			infectOccupants();
		}
	}
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
/// Returns the 
/// </summary>
/// <returns></returns>
bool Building::checkInfected()
{
	return isInfected;
}

/// <summary>
/// Sets isInfected to true
/// </summary>
void Building::infect()
{
	isInfected = true;
}

/// <summary>
/// Adds NPC to vector of 
/// occupants
/// </summary>
/// <param name="n"></param>
void Building::addOccupant(NPC * n)
{
	m_occupants.push_back(n);
}

/// <summary>
/// Sets m_infected member attribute
/// of any NPC in building to true
/// </summary>
void Building::infectOccupants()
{
	for each (NPC * n in m_occupants)
	{
		n->setPoisoned(true);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="p"></param>
bool Building::insideBounds(sf::Vector2f p)
{
	//Check if cursor is within radius of circle
	if (p.x > m_position.x - infectionRadius && p.x < m_position.x + infectionRadius
		&& p.y > m_position.y - infectionRadius && p.y < m_position.y + infectionRadius)
	{
		return true;
	}

	//Otherwise return false;
	return false;
}
