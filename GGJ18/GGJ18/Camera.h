#ifndef CAMERA_H
#define CAMERA_H

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

	void render(sf::RenderWindow &window);

private:
	Cursor* m_cursor;

	sf::Vector2f m_position;
	sf::Vector2f m_outputCentre;

	float m_scrollArea;

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
