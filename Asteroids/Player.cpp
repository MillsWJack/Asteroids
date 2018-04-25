#include "Player.h"

Player::Player(float XSize, float YSize, float XPos, float YPos)
{
	m_XSize = XSize;
	m_YSize = YSize;
	m_XPos = XPos;
	m_YPos = YPos;

	m_PolygonShape.setRadius(m_XSize);
	m_PolygonShape.setPointCount(m_YSize);
	m_PolygonShape.setOrigin(30, 30);

	m_PolygonShape.setFillColor(sf::Color::Black);
	m_PolygonShape.setOutlineColor(sf::Color::White);
	m_PolygonShape.setOutlineThickness(1);
}

Player::~Player()
{
}