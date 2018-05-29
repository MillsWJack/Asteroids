#pragma once

#include "Entity.h"

class Player: public Entity
{
public:
	Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity);
	~Player();

	void SetSpriteType(int spriteNum);
};

