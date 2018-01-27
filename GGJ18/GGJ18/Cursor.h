#ifndef CURSOR_H
#define CURSOR_H

#include <SFML\Graphics.hpp>

class Cursor
{
public:
	//Constructors - Destructors
	Cursor();
	~Cursor();

	//Member functions
	void update(sf::Window & window);
	void render(sf::RenderWindow & window);
	bool checkCollision(sf::Vector2f p, sf::Vector2f s);
	bool checkCollision(float x, float y, float w, float h);
	bool checkCollision(sf::Vector2f p, float r);
	bool checkCollision(float x, float y, float r);

	//Getters - Setters
	sf::Vector2f getPosition();

private:
	//Member attributes
	sf::Vector2f m_position;
	sf::CircleShape cursorPoint;
	sf::Mouse m_mouse;
};

#endif // !CURSOR_H
