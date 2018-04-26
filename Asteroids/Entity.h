#pragma once

#include <SFML\Graphics.hpp>

#define M_PI 3.1459265

class Entity
{
public:
	Entity(sf::Vector2f size, sf::Vector2f pos, float speed);
	~Entity();

	float m_Rotation;

	sf::CircleShape m_PolygonShape;

	void Move();
	void Rotate(float angle);
	void Render(sf::RenderWindow& window);
	void virtual Update();
	void HandleScreenCollisions();

	sf::Vector2f& GetPos() { return m_Pos; }
	sf::Vector2f& GetSize() { return m_Size; }

private:
	sf::Vector2f m_Pos;
	sf::Vector2f m_Size;

	float m_MoveSpeed;
};

