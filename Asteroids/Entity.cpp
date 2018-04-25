#include "Entity.h"

Entity::Entity():
	m_Rotation(m_PolygonShape.getRotation())
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

void Entity::Rotate(float angle)
{
	m_PolygonShape.setRotation(m_Rotation += angle);

	if (m_Rotation >= 360)
	{
		m_Rotation = 0;
	}
}

void Entity::Render(sf::RenderWindow& window)
{
	m_PolygonShape.setPosition(m_XPos, m_YPos);
	window.draw(m_PolygonShape);
}

void Entity::Update()
{
	HandleScreenCollisions();
}

void Entity::HandleScreenCollisions()
{
	//check up
	if (this->m_YPos <= 0)
	{
		m_YPos = 0;
	}
	//check down
	else if (this->m_YPos >= 1080)
	{
		m_YPos = 1080;
	}
	//check right
	else if (this->m_XPos + (this->m_PolygonShape.getRadius()) >= 1920)
	{
		m_XPos = 1920 - (this->m_PolygonShape.getRadius());
	}
	//check left
	else if (this->m_XPos <= this->m_PolygonShape.getRadius())
	{
		m_XPos = this->m_PolygonShape.getRadius();
	}
}
