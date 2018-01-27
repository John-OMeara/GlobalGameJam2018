#ifndef CURSOR_H

#include <SFML/Graphics.hpp>

class Cursor
{
public:
	sf::Vector2f getPosition() {
		return m_position;
	}
	float getRotation() {
		return m_rotation;
	}

private:

};

#endif !CURSOR_H