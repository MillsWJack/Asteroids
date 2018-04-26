#include "Game.h"

Game::Game():
	m_Window(sf::Vector2u(1920,1080), "Asteroids"),
	m_Player(30, 3, 1920 / 2, 1080 / 2)
{
}

Game::~Game()
{
}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//Rotate ship left
		m_Player.Rotate(-5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//Rotate ship right
		m_Player.Rotate(5);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//Move ship forward
		m_Player.Move();
	}
}

void Game::Update()
{
	m_Window.Update();
	m_Player.Update();

	//~~~DEBUG OUTPUTS~~~//
	system("CLS");
	std::cout << "Player Rotation: " << m_Player.m_Rotation << std::endl;
	std::cout << "Player xPos: " << m_Player.m_XPos << std::endl;
	std::cout << "Player yPos: " << m_Player.m_YPos << std::endl;
}

void Game::Render()
{
	m_Window.StartDraw();
	
	//Draw here
	m_Player.Render(*m_Window.GetRenderWindow());

	m_Window.EndDraw();
}