#include "Entity.h"

Entity::Entity():
	m_Rotation(m_PolygonShape.getRotation())
{
}

Entity::~Entity()
{
}

void Entity::Move()
{
	m_XPos += (sin((M_PI / 180) * m_Rotation) * m_MoveSpeed);
	m_YPos += (-cos((M_PI / 180) * m_Rotation) * m_MoveSpeed);
}

void Entity::Rotate(float angle)
{
	m_PolygonShape.setRotation(m_Rotation += angle);

	if (m_Rotation >= 360 || m_Rotation <= -360)
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
	if (m_YPos + m_PolygonShape.getRadius() < 0)
	{
		m_YPos = 1080;
	}
	//check down
	else if (m_YPos - m_PolygonShape.getRadius() > 1080)
	{
		m_YPos = 0;
	}
	//check right
	else if (m_XPos - (m_PolygonShape.getRadius()) > 1920)
	{
		m_XPos = 0;
	}
	//check left
	else if (m_XPos + m_PolygonShape.getRadius() < 0)
	{
		m_XPos = 1920;
	}
}
