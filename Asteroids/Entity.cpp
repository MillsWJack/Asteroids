#include "Entity.h"

Entity::Entity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f accelleration):
	m_Rotation(m_PolygonShape.getRotation()),
	m_Size(size),
	m_Pos(pos),
	m_Velocity(velocity),
	m_Acceleration(accelleration)
{
	m_VelocityLimit = 20;
	m_Thrust = 1;
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

	m_Acceleration.x += m_Thrust * (sin(angle));
	m_Acceleration.y += m_Thrust * (-cos(angle));
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
	//Update position and velocity
	m_Pos += m_Velocity;
	m_Velocity += m_Acceleration;

	//Limit Velocity
	LimitVelocity();

	//Reset acceleration
	m_Acceleration.x = 0;
	m_Acceleration.y = 0;

	//Check collisions
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

void Entity::LimitVelocity()
{
	if (m_Velocity.x >= m_VelocityLimit)
	{
		m_Velocity.x = m_VelocityLimit;
	}
	if (m_Velocity.x <= -m_VelocityLimit)
	{
		m_Velocity.x = -m_VelocityLimit;
	}
	if (m_Velocity.y >= m_VelocityLimit)
	{
		m_Velocity.y = m_VelocityLimit;
	}
	if (m_Velocity.y <= -m_VelocityLimit)
	{
		m_Velocity.y = -m_VelocityLimit;
	}
}