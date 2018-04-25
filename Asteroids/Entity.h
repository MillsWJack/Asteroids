#pragma once

#include <SFML\Graphics.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	float m_XPos, m_YPos;
	float m_XSize, m_YSize;
	float m_MoveSpeed;
	float m_Rotation;

	sf::CircleShape m_PolygonShape;

	void Move(float xOff, float yOff = 0);
	void Rotate(float angle);
	void Render(sf::RenderWindow& window);
	void Update();
	void HandleScreenCollisions();
};

