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
		m_Player.Move(5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//Move ship backwards
		m_Player.Move(-5);
	}
}

void Game::Update()
{
	m_Window.Update();
	m_Player.Update();

	std::cout << "Player Rotation: " << m_Player.m_Rotation << std::endl;
}

void Game::Render()
{
	m_Window.StartDraw();
	
	//Draw here
	m_Player.Render(*m_Window.GetRenderWindow());

	//~~~DEBUG~~~
	//Drawing point at head of ship
	sf::RectangleShape shape;
	shape.setPosition(m_Player.m_XPos, m_Player.m_YPos - m_Player.m_PolygonShape.getRadius());
	shape.setSize(sf::Vector2f(5, 5));
	m_Window.GetRenderWindow()->draw(shape);
	//~~~DEBUG~~~

	m_Window.EndDraw();
}