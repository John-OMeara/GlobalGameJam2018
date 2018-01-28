#ifndef WELL_H
#define WELL_H

#include "Building.h"

class Well : Building
{
public:
	//Constructors - Destructors
	Well(sf::Texture t, sf::Vector2f p);
	~Well();

	//Member functions
	void poisonWell();
	void affectOccupants();

	//Getters - Setters

private:
	bool isPoisoned;

};

#endif // !WELL_H