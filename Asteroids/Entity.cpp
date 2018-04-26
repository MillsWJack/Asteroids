#include "Entity.h"

Entity::Entity(sf::Vector2f size, sf::Vector2f pos, float speed):
	m_Rotation(m_PolygonShape.getRotation()),
	m_Size(size),
	m_Pos(pos),
	m_MoveSpeed(speed)
{
	m_PolygonShape.setRadius(m_Size.x);
	m_PolygonShape.setPointCount(m_Size.y);
}

Entity::~Entity()
{
}

void Entity::Move()
{
	//Convert angle from degrees to radians
	double angle = (M_PI / 180) * m_Rotation;

	m_Pos.x += (sin(angle)) * m_MoveSpeed;
	m_Pos.y += (-cos(angle)) * m_MoveSpeed;
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
	m_PolygonShape.setPosition(m_Pos.x, m_Pos.y);
	window.draw(m_PolygonShape);
}

void Entity::Update()
{
	HandleScreenCollisions();
}

void Entity::HandleScreenCollisions()
{
	//check up
	if (m_Pos.y + m_PolygonShape.getRadius() < 0)
	{
		m_Pos.y = 1080;
	}
	//check down
	else if (m_Pos.y - m_PolygonShape.getRadius() > 1080)
	{
		m_Pos.y = 0;
	}
	//check right
	else if (m_Pos.x - (m_PolygonShape.getRadius()) > 1920)
	{
		m_Pos.x = 0;
	}
	//check left
	else if (m_Pos.x + m_PolygonShape.getRadius() < 0)
	{
		m_Pos.x = 1920;
	}
}
