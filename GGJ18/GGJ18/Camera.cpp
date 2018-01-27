#include "Camera.h"

Camera::Camera()
{
	init();
}

Camera::Camera(Cursor* cursor)
	: m_cursor(cursor)
{
	init();
}

void Camera::init()
{
	m_view.setSize(sf::Vector2f(800, 800));
	m_view.zoom(0.2);

	m_miniMap.setViewport(sf::FloatRect(0.1, 0.7, 0.3, 0.3));

	m_weight = 0.1;
	m_shake = 0.1;
	m_maxAngle = 0.5;
	m_maxOffset = 1;
}

void Camera::update()
{
	sf::Vector2f cursorPos = m_cursor->getPosition();
	float cursorRotation = m_cursor->getRotation();

	cursorPos.x += cos(cursorRotation*acos(-1) / 180) * m_viewOffset;
	cursorPos.y += sin(cursorRotation*acos(-1) / 180) * m_viewOffset;

	m_position.x += (cursorPos.x - m_position.x)*m_weight;
	m_position.y += (cursorPos.y - m_position.y)*m_weight;

	m_outputCentre = m_position;

	m_view.setCenter(m_position);
	m_view.setRotation(0);


	if (m_shaking)
	{
		m_angle = m_maxAngle * m_shake * (((float)rand()) / RAND_MAX * 100.0 - 50.0);

		m_offsetX = m_maxOffset * m_shake * (((float)rand()) / RAND_MAX * 100.0 - 50.0);
		m_offsetY = m_maxOffset * m_shake * (((float)rand()) / RAND_MAX * 100.0 - 50.0);

		m_outputCentre.x += m_offsetX;
		m_outputCentre.y += m_offsetY;
		m_view.setRotation(m_angle);
	}


	m_view.setCenter(m_outputCentre);
}

void Camera::render(sf::RenderWindow &window)
{

}