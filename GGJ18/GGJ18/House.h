#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"

class House : public Building
{
public:
	//Constructors - Deconstructor
	House(sf::Texture t, sf::Vector2f p);
	~House();

	//Member functions

	//Getters - Setters

private:


};

#endif // !HOUSE_H