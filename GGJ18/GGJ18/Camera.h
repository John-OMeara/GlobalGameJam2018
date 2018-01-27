#ifndef CAMERA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Cursor.h"

class Camera
{
public:
	Camera();
	Camera(Cursor* cursor);

	void init();
	void update();

	sf::View m_view;
	sf::View m_miniMap;

	void render(sf::RenderWindow &window);

private:
	Cursor* m_cursor;

	sf::Vector2f m_position;
	sf::Vector2f m_outputCentre;

	sf::FloatRect m_playerBoundary;

	int m_viewOffset;
	float m_weight;

	bool m_shaking;
	float m_shake;

	float m_angle;
	float m_maxAngle;

	float m_offsetX;
	float m_offsetY;
	float m_maxOffset;
};

#endif !CAMERA_H
