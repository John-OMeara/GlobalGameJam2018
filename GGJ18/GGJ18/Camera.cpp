#include "Camera.h"

Camera::Camera()
{
	init();
}

Camera::Camera(Cursor* cursor)
	: m_cursor(cursor),
	m_weight(0.1),
	m_shake(0.1),
	m_maxAngle(0.5),
	m_maxOffset(1),
	m_scrollArea(150),
	m_scrollSpeed(5)
{
	init();
}

void Camera::init()
{
	m_view.setSize(sf::Vector2f(800, 600));
	//m_view.setViewport(sf::FloatRect(0, 0, 1, 1));
}


void Camera::update()
{
	sf::Vector2f cursorPos = m_cursor->getPosition();

	//m_position.x += (cursorPos.x - m_position.x)*m_weight;
	//m_position.y += (cursorPos.y - m_position.y)*m_weight;

	if (cursorPos.x < m_scrollArea
		&& m_position.x > 0)
	{
		m_position.x -= m_scrollSpeed;
	}
	if (cursorPos.x > 800 - m_scrollArea
		&& m_position.x < 800)
	{
		m_position.x += m_scrollSpeed;
	}

	if (cursorPos.y < m_scrollArea
		&& m_position.y > 0)
	{
		m_position.y -= m_scrollSpeed;
	}
	if (cursorPos.y > 600 - m_scrollArea
		&& m_position.y < 600)
	{
		m_position.y += m_scrollSpeed;
	}

	m_outputCentre = m_position;

	m_view.setCenter(m_position);

	m_view.setRotation(0);

	std::cout << "(" << m_position.x << ", " << m_position.y << ")" << std::endl;


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