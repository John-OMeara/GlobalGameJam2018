#include "Cursor.h"

/// <summary>
/// Default constructor for cursor class
/// </summary>
Cursor::Cursor() :
	m_position(sf::Vector2f(0,0))
{
	cursorPoint.setFillColor(sf::Color::Transparent);
	cursorPoint.setRadius(25.f);
	cursorPoint.setOutlineColor(sf::Color::Red);
	cursorPoint.setOutlineThickness(5.f);
	cursorPoint.setOrigin(cursorPoint.getRadius(), cursorPoint.getRadius());
}

/// <summary>
/// Deconstructor
/// </summary>
Cursor::~Cursor()
{
}

/// <summary>
/// Updates position of cursor and checks
/// for mouse clicks
/// </summary>
void Cursor::update(sf::RenderWindow & window, sf::View gameView)
{
	//Set cursor object position to current mouse position
	//m_position.x = m_mouse.getPosition(window).x;
	//m_position.y = m_mouse.getPosition(window).y;
	m_position = sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

	//Set circleshape to cursor position
	cursorPoint.setPosition(m_position);
}

/// <summary>
/// Renders cursor primitive object
/// </summary>
void Cursor::draw(sf::RenderWindow & window)
{
	//Draw circleshape to represent cursor
	window.draw(cursorPoint);
}

/// <summary>
/// Performs AABB collision check to
/// see if object was clicked
/// </summary>
/// <param name="position"></param>
/// <param name="size"></param>
/// <returns></returns>
bool Cursor::checkCollision(sf::Vector2f p, sf::Vector2f s)
{
	//Check if cursor is inside AABB
	if (m_position.x > p.x && m_position.x < p.x + s.x
		&& m_position.y > p.y && m_position.y < p.y + s.y)
	{
		//Check if left mouse button is pressed
		if (m_mouse.isButtonPressed(sf::Mouse::Left))
		{
			//If so return true
			return true;
		}
	}

	//Otherwise return false
	return false;
}

/// <summary>
/// Performs AABB collision check to
/// see if object was clicked
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <returns></returns>
bool Cursor::checkCollision(float x, float y, float w, float h)
{
	//Check if cursor is inside AABB
	if (m_position.x > x && m_position.x < x + w
		&& m_position.y > y && m_position.y < y + h)
	{
		//Check if left mouse button is pressed
		if (m_mouse.isButtonPressed(sf::Mouse::Left))
		{
			//If so return true
			return true;
		}
	}

	//Otherwise return false
	return false;
}

/// <summary>
/// Performs radius collision check to
/// see if object was clicked
/// </summary>
/// <param name="position"></param>
/// <param name="r"></param>
/// <returns></returns>
bool Cursor::checkCollision(sf::Vector2f p, float r)
{
	//Check if cursor is within radius of circle
	if (m_position.x > p.x - r && m_position.x < p.x + r
		&& m_position.y > p.y - r && m_position.y < p.y + r)
	{
		//Check if left mouse button is pressed
		if (m_mouse.isButtonPressed(sf::Mouse::Left))
		{
			//If so return true
			return true;
		}
	}

	//Otherwise return false;
	return false;
}

/// <summary>
/// Performs radius collision check to
/// see if object was clicked
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="r"></param>
/// <returns></returns>
bool Cursor::checkCollision(float x, float y, float r)
{
	//Check if cursor is within radius of circle
	if (m_position.x > x - r && m_position.x < x + r
		&& m_position.y > y - r && m_position.y < y + r)
	{
		//Check if left mouse button is pressed
		if (m_mouse.isButtonPressed(sf::Mouse::Left))
		{
			//If so return true
			return true;
		}
	}

	//Otherwise return false;
	return false;
}
