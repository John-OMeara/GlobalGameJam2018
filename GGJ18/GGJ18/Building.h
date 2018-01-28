#ifndef BUILDING_H
#define BUILDING_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include "NPC.h"

class Building
{
public:
	//Constructors - Destructors
	Building(sf::Texture t, sf::Vector2f p);
	~Building();

	//Member functions
	void update();
	void draw(sf::RenderWindow & window);
	void infect();
	void addOccupant(NPC * n);
	void infectOccupants();
	bool insideBounds(sf::Vector2f p);

	//Getters - Setters
	bool checkInfected();

protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position;
	sf::Vector2f m_size; //Texture globalBounds
	bool isInfected;
	float infectionRadius = 10.f;
	std::vector<NPC *> m_occupants;

private:

};

#endif // !BUILDING_H