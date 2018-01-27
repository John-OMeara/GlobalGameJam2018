#include "Menu.h"

Menu::Menu()
{
	m_placeholder.setPosition(600, 0);
	m_placeholder.setSize(sf::Vector2f(200, 600));
	m_placeholder.setFillColor(sf::Color::Blue);
}

void Menu::update()
{

}

void Menu::draw(sf::RenderWindow & window)
{
	window.draw(m_placeholder);
}
