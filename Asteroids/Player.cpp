#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f pos, float speed):
	Entity(size, pos, speed)
{
	m_PolygonShape.setOrigin(30, 30);
	m_PolygonShape.setFillColor(sf::Color::Black);
	m_PolygonShape.setOutlineThickness(1);
}

Player::~Player()
{
}