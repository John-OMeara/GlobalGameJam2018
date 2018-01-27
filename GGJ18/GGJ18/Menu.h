#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu();

	void update();
	void draw(sf::RenderWindow &window);

private:
	sf::RectangleShape m_placeholder;
};

#endif !MENU_H