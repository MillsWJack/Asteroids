#pragma once

#include <SFML\Graphics.hpp>

#include "Entity.h"

class Player: public Entity
{
public:
	Player(float XSize, float YSize, float XPos, float YPos);
	~Player();

private:
	sf::Vector2f m_HeadPosition;
};

