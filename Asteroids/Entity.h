#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	float m_XPos, m_YPos;
	float m_MoveSpeed;

	void Move(float xOff, float yOff);
};

