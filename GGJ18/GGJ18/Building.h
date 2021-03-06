#ifndef BUILDING_H
#define BUILDING_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Building
{
public:
	//Constructors - Destructors
	Building(sf::Texture t, sf::Vector2f p);
	~Building();

	//Member functions
	void update();
	void draw(sf::RenderWindow & window);

	//Getters - Setters

protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position;
	sf::Vector2f m_size; //Texture globalBounds

private:

};

#endif // !BUILDING_H