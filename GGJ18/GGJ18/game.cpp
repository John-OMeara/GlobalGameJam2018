// author Peter Lowe

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_menu(),
	m_cursor(),
	m_camera(&m_cursor),
	m_exitGame{false} //when true game will exit
{
	setupSprite(); // load texture

    //Load image tild for texture
	if (!house_tex.loadFromFile(".\\ASSETS\\IMAGES\\House.png"))
	{
		//Error message for file loading failure
		std::cout << "ERROR: Failed to load file: " << __FILE__ << " at line : " << __LINE__ << std::endl;
	}

	houses.push_back(new House(house_tex, sf::Vector2f(200, 200)));
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	m_cursor.update(m_window,m_camera.m_view);
	m_camera.update();
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);

	m_window.setView(m_camera.m_view);
	m_window.draw(m_logoSprite);

	m_window.setView(m_window.getDefaultView());
	m_menu.draw(m_window);

	m_cursor.draw(m_window);

	m_window.setView(m_camera.m_view);
	m_cursor.draw(m_window);

	for (int i = 0; i < houses.size(); i++)
	{
		houses.at(i)->draw(m_window);
	}

	m_window.display();
}


/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("./ASSETS/IMAGES/TESTMAP.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading file: " << __FILE__ << ":" << __LINE__ << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
}
