
#ifndef NPC_H
#define NPC_H

#include <SFML\Graphics.hpp>
#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>
#include <iostream>

class NPC
{
public:
	//Constructors - Destructors
	NPC();
	~NPC();

	//Member functions
	void update();
	void draw(sf::RenderWindow & window);
	void setupSprite(); // load texture
	sf::Vector2f setRandPoint();
	void setInfected();
	void checkInfection();
	//Getters - Setters
	sf::Vector2f getPosition();
	void setPostion(sf::Vector2f pos);

private:

	sf::RectangleShape m_NPC;
	sf::CircleShape m_NPCRadius;

		//Member attributes
	sf::Vector2f m_position;
	sf::Vector2f m_endPostion;
	sf::Vector2f m_detination;
	sf::Vector2f m_velocity{ 0,0 };
	float m_speed = 5;

	bool m_infected  ;
	bool m_reachedEnd = false;

	sf::Vector2f m_dest{ 0,0 };
	float m_dist;
	sf::Vector2f  m_size{ 40,40 };
	float m_infectionRadius = 50;

	sf::Texture m_npcTexture;
	

};

#endif // !PLAYER_H


