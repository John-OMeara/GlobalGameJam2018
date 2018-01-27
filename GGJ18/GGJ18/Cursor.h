#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>

class Cursor
{
public:
	sf::Vector2f getPosition() {
		return sf::Vector2f(0,0);
	}
	float getRotation() {
		return 0;
	}

private:

};

#endif !CURSOR_H