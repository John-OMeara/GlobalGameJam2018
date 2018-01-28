#include "NPC.h"

NPC::NPC()
{
	//	setupSprite();
	/* initialize random seed: */
	srand(time(NULL));
	setPostion(m_position);
	m_NPC.setFillColor(sf::Color::Red);
	m_NPC.setRadius(m_radius);
	m_NPC.setOutlineColor(sf::Color::Green);
	m_NPC.setOutlineThickness(5.f);
	m_NPC.setOrigin(m_radius,m_radius);

	m_NPCRadius.setFillColor(sf::Color::Transparent); //remove all
	m_NPCRadius.setRadius(m_infectionRadius);
	m_NPCRadius.setOutlineColor(sf::Color::Red);
	m_NPCRadius.setOutlineThickness(5.f);
	m_NPCRadius.setOrigin(m_infectionRadius,m_infectionRadius);



}

NPC::~NPC()
{
}

void NPC::update()
{

	setPostion(m_position);
	m_npcSprite.setPosition(m_position);//remove
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
	if (!m_npcTexture.loadFromFile("./ASSETS/IMAGES/SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading file: " << __FILE__ << ":" << __LINE__ << std::endl;
	}
	m_npcSprite.setTexture(m_npcTexture);
}

sf::Vector2f NPC::setRandPoint()
{
	m_endPostion.x = rand() % 800;
	m_endPostion.y = rand() % 600;

	
	return m_endPostion;
}


void NPC::setPostion(sf::Vector2f pos)
{
	
	
	m_dest.x = m_endPostion.x - m_position.x  ;
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
