#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include<iostream>

class Menu
{
public:
	Menu();

	void update();
	void draw(sf::RenderWindow &window);

	sf::Text m_btnOne;
	sf::Text m_btnTwo;
	sf::Text m_btnThree;
	sf::Text m_btnFour;

	sf::Font m_font;

	bool m_btnOneAlive;
	bool m_btnTwoAlive;
	bool m_btnThreeAlive;
	bool m_btnFourAlive;





private:
	sf::RectangleShape m_placeholder;
	sf::RectangleShape m_buttonOne;
	sf::RectangleShape m_buttonTwo;
	sf::RectangleShape m_buttonThree;
	sf::RectangleShape m_buttonFour;
};

#endif !MENU_H