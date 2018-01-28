#include "NPC.h"

NPC::NPC()
{
	//	setupSprite();
	/* initialize random seed: */
	srand(time(NULL));
	setPostion(m_position);
	setupSprite();
	//m_NPC.setFillColor(sf::Color::Red);
	//m_NPC.setOutlineColor(sf::Color::Green);
	m_NPC.setSize(m_size);
	m_NPC.setOrigin(m_size.x / 2, m_size.y / 2);

	m_NPCRadius.setFillColor(sf::Color::Transparent); //remove all
	m_NPCRadius.setRadius(m_infectionRadius);
	m_NPCRadius.setOutlineColor(sf::Color::Red);
	m_NPCRadius.setOutlineThickness(5.f);
	m_NPCRadius.setOrigin(m_infectionRadius, m_infectionRadius);



}

NPC::~NPC()
{
}

void NPC::update()
{

	setPostion(m_position);
	m_NPCRadius.setPosition(m_position);

}

void NPC::draw(sf::RenderWindow & window)
{
	window.draw(m_NPC);
	window.draw(m_NPCRadius);


}

bool NPC::checkCollision(float x, float y, float w, float h)
{
	return false;
}

void NPC::setupSprite()
{
	int randTexture = rand() % 2;

	if (randTexture == 0)
	{
		if (!m_npcTexture.loadFromFile("./ASSETS/IMAGES/meeple1.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading file: " << __FILE__ << ":" << __LINE__ << std::endl;
		}
	}
	else if (randTexture == 1)
	{
		if (!m_npcTexture.loadFromFile("./ASSETS/IMAGES/meeple2.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading file: " << __FILE__ << ":" << __LINE__ << std::endl;
		}
	}
	else if (randTexture == 2)
	{
		if (!m_npcTexture.loadFromFile("./ASSETS/IMAGES/meeple3.png"))
		{
			// simple error message if previous call fails
			std::cout << "problem loading file: " << __FILE__ << ":" << __LINE__ << std::endl;
		}
	}

	m_NPC.setTexture(&m_npcTexture);
}

sf::Vector2f NPC::setRandPoint()
{
	m_endPostion.x = rand() % 800;
	m_endPostion.y = rand() % 600;


	return m_endPostion;
}

void NPC::setPoisoned(bool c)
{
	m_infected = c;
}


void NPC::setPostion(sf::Vector2f pos)
{


	m_dest.x = m_endPostion.x - m_position.x;
	m_dest.y = m_endPostion.y - m_position.y;

	m_dist = sqrt((m_dest.x*m_dest.x) + (m_dest.y * m_dest.y));

	if (m_dist >= 5)
	{
		m_velocity.x = (m_dest.x / m_dist)*m_speed;
		m_velocity.y = (m_dest.y / m_dist)*m_speed;

		m_position.x += m_velocity.x;
		m_position.y += m_velocity.y;
	}
	else
	{
		m_endPostion = setRandPoint();
	}
	m_NPC.setPosition(pos);

}
