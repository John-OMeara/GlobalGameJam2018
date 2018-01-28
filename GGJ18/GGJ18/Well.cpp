#include "Well.h"

/// <summary>
/// Well constructor
/// calls superclass
/// constructor 
/// </summary>
/// <param name="t"></param>
/// <param name="p"></param>
Well::Well(sf::Texture t, sf::Vector2f p):
	Building(t, p),
	isPoisoned(false)
{

}

/// <summary>
/// Deconstructor
/// </summary>
Well::~Well()
{
}

/// <summary>
/// Set the well to be poisoned
/// </summary>
void Well::poisonWell()
{
	isPoisoned = true;
}

/// <summary>
/// Applies infection to users of the well
/// </summary>
void Well::affectOccupants()
{
	//Apply infection to occupants
	/*
	for each NPC in vector
		NPC.setPoisoned(true);
	*/
}