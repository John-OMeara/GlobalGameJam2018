#include "Menu.h"

Menu::Menu()
{

	if (!m_font.loadFromFile("./ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "Error loading file" << std::endl;
	}


	m_placeholder.setPosition(600, 0);
	m_placeholder.setSize(sf::Vector2f(200, 600));
	m_placeholder.setFillColor(sf::Color::Blue);

	m_buttonOne.setSize(sf::Vector2f(100, 30));
	m_buttonOne.setOutlineColor(sf::Color::Green);
	m_buttonOne.setFillColor(sf::Color::Green);
	m_buttonOne.setOutlineThickness(2);
	m_buttonOne.setPosition(650, 20);
	m_btnOne.setFont(m_font);
	m_btnOne.setCharacterSize(20);
	m_btnOne.setPosition(sf::Vector2f(665, 15));
	m_btnOne.setString("one");
	

	m_buttonTwo.setSize(sf::Vector2f(100, 30));
	m_buttonTwo.setOutlineColor(sf::Color::Green);
	m_buttonTwo.setFillColor(sf::Color::Green);
	m_buttonTwo.setOutlineThickness(2);
	m_buttonTwo.setPosition(650, 60);
	m_btnTwo.setFont(m_font);
	m_btnTwo.setCharacterSize(20);
	m_btnTwo.setPosition(sf::Vector2f(665, 55));
	m_btnTwo.setString("Two");


	m_buttonThree.setSize(sf::Vector2f(100, 30));
	m_buttonThree.setOutlineColor(sf::Color::Green);
	m_buttonThree.setFillColor(sf::Color::Green);
	m_buttonThree.setOutlineThickness(2);
	m_buttonThree.setPosition(650, 100);
	m_btnThree.setFont(m_font);
	m_btnThree.setCharacterSize(20);
	m_btnThree.setPosition(sf::Vector2f(665, 95));
	m_btnThree.setString("Two");



	m_buttonFour.setSize(sf::Vector2f(100, 30));
	m_buttonFour.setOutlineColor(sf::Color::Green);
	m_buttonFour.setFillColor(sf::Color::Green);
	m_buttonFour.setOutlineThickness(2);
	m_buttonFour.setPosition(650, 140);
	m_btnFour.setFont(m_font);
	m_btnFour.setCharacterSize(20);
	m_btnFour.setPosition(sf::Vector2f(665, 135));
	m_btnFour.setString("Two");



}



void Menu::update()
{

}


void Menu::draw(sf::RenderWindow & window)
{
	window.draw(m_placeholder);
	window.draw(m_buttonOne);
	window.draw(m_buttonTwo);
	window.draw(m_buttonThree);
	window.draw(m_buttonFour);
	window.draw(m_btnOne);
	window.draw(m_btnTwo);
	window.draw(m_btnThree);
	window.draw(m_btnFour);
}


