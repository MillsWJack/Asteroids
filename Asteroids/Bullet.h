#pragma once
#include "Entity.h"

class Bullet: public Entity
{
public:
	Bullet(sf::Vector2f size, sf::Vector2f pos, float speed);
	~Bullet();
};

