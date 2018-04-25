#pragma once

#include <SFML\Graphics.hpp>
#include "window.h"

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
};

