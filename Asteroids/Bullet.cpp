#include "Bullet.h"

Bullet::Bullet(sf::Vector2f size, sf::Vector2f pos, float speed):
	Entity(size, pos, speed)
{
	m_PolygonShape.setFillColor(sf::Color::White);
}

Bullet::~Bullet()
{
}
