#pragma once

#include <SFML\Graphics.hpp>

#define M_PI 3.1459265

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

	void Move();
	void Rotate(float angle);
	void Render(sf::RenderWindow& window);
	void Update();
	void HandleScreenCollisions();
};

