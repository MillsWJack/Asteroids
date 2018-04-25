#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Move(float xOff, float yOff)
{
	m_XPos += xOff;
	m_YPos += yOff;
}
