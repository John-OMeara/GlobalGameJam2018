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
	m_view.setSize(sf::Vector2f(800, 600));
	//m_view.setViewport(sf::FloatRect(0, 0, 1, 1));

	m_weight = 0.1;
	m_shake = 0.1;
	m_maxAngle = 0.5;
	m_maxOffset = 1;
}


void Camera::update()
{
	sf::Vector2f cursorPos = m_cursor->getPosition();

	m_position.x += (cursorPos.x - m_position.x)*m_weight;
	m_position.y += (cursorPos.y - m_position.y)*m_weight;

	m_outputCentre = m_position;

	//m_view.setCenter(m_position);


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


	//m_view.setCenter(m_outputCentre);
}

void Camera::render(sf::RenderWindow &window)
{

}