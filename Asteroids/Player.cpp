#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity):
	Entity(size, pos, velocity)
{
	m_PolygonShape.setOrigin(30, 30);
	m_PolygonShape.setFillColor(sf::Color::Black);
	m_PolygonShape.setOutlineThickness(1);
}

Player::~Player()
{
}