
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
	bool checkCollision(float x, float y, float w, float h);
	void setupSprite(); // load texture
	sf::Vector2f setRandPoint();
	void setPoisoned(bool c);

	//Getters - Setters
	sf::Vector2f getPosition() {
		return m_position;
	}
	void setPostion(sf::Vector2f pos);

private:

	sf::CircleShape m_NPC;
	sf::CircleShape m_NPCRadius;
		//Member attributes
	sf::Vector2f m_position{ 0,0 };
	sf::Vector2f m_endPostion{ 400,400 };
	sf::Vector2f m_detination;
	sf::Vector2f m_velocity{ 0,0 };
	float m_speed = 5;
	bool m_infected;
	bool m_reachedEnd = false;
	sf::Vector2f m_dest{ 0,0 };
	float m_dist;
	float  m_radius = 20;
	float m_infectionRadius = 40;

	sf::Texture m_npcTexture;
	sf::Sprite m_npcSprite;

};

#endif // !PLAYER_H


