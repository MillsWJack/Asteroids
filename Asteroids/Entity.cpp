#include "Entity.h"

Entity::Entity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f accelleration, int sprite):
	m_Size(size),
	m_Pos(pos),
	m_Velocity(velocity),
	m_Acceleration(accelleration),
	m_SpriteNum(sprite)
{
	m_VelocityLimit = 20;
	m_Thrust = 0.1;
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
	m_Sprite.setRotation(m_Rotation += angle);

	if (m_Rotation >= 360 || m_Rotation <= -360)
	{
		m_Rotation = 0;
	}
}

void Entity::Render(sf::RenderWindow& window)
{
	//m_PolygonShape.setPosition(m_Pos.x, m_Pos.y);
	m_Sprite.setPosition(m_Pos.x, m_Pos.y);
	window.draw(m_Sprite);
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
	if (m_Pos.y + m_Sprite.getTextureRect().height / 2< 0)
	{
		m_Pos.y = 1080;
	}
	//check down
	else if (m_Pos.y - m_Sprite.getTextureRect().height / 2 > 1080)
	{
		m_Pos.y = 0;
	}
	//check right
	else if (m_Pos.x - m_Sprite.getTextureRect().width / 2 > 1920)
	{
		m_Pos.x = 0;
	}
	//check left
	else if (m_Pos.x + m_Sprite.getTextureRect().width / 2 < 0)
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