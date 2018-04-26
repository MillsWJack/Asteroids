#pragma once

#include <SFML\Graphics.hpp>

#include "window.h"
#include "Player.h"
#include "Bullet.h"

#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	window* GetWindow() { return &m_Window; }

private:
	window m_Window;
	Player m_Player;

	std::vector<Bullet*> m_BulletList;
};

