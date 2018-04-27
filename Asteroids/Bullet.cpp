#include "Bullet.h"

Bullet::Bullet(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity):
	Entity(size, pos, velocity)
{
	m_PolygonShape.setFillColor(sf::Color::White);
}

Bullet::~Bullet()
{
}
