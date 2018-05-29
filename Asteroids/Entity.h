#pragma once

#include <SFML\Graphics.hpp>

#define M_PI 3.1459265

class Entity
{
public:
	Entity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f accelleration = { 2, 2 }, int sprite = 0);
	~Entity();

	void Move();
	void Rotate(float angle);
	void Render(sf::RenderWindow& window);
	
	void virtual Update();

	void HandleScreenCollisions();
	void LimitVelocity();

	sf::Vector2f& GetPos() { return m_Pos; }
	sf::Vector2f& GetSize() { return m_Size; }
	sf::Vector2f& GetVelocity() { return m_Velocity; }

	float GetRotation() { return m_Rotation; }

	sf::Texture& GetTexture() { return m_Texture; }

	sf::Image& GetImage() { return m_Image; }

	sf::Sprite& GetSprite() { return m_Sprite; }
	int& GetSpriteNum() { return m_SpriteNum; }

private:
	sf::Vector2f m_Pos;
	sf::Vector2f m_Acceleration;
	sf::Vector2f m_Size;
	sf::Vector2f m_Velocity;

	int m_SpriteNum;

	float m_Thrust;
	float m_Acelleration;
	float m_Force;
	float m_Rotation;
	float m_VelocityLimit;

	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	sf::Image m_Image;
};

