#include "Game.h"

Game::Game():
	m_Window(sf::Vector2u(1920,1080), "Asteroids"),
	m_Player(sf::Vector2f(30, 3), sf::Vector2f(1920 / 2, 1000), sf::Vector2f(1,1))
{
	m_Clock.restart();
	m_Elapsed = 0.0f;
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
		//Move ship forward and change sprite animation based on time	
		m_Player.Move();
		if (m_Clock.getElapsedTime().asMicroseconds() % 2 == 0)
		{
			m_Player.SetSpriteType(2);
		}
		else
		{
			m_Player.SetSpriteType(1);
		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//Change sprite
		m_Player.SetSpriteType(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Bullet* bullet = new Bullet(sf::Vector2f(5, 100), m_Player.GetPos(), sf::Vector2f(2,2));
		m_BulletList.push_back(bullet);
	}
}

void Game::Update()
{
	m_Window.Update();

	float timestep = 1.0f / 60;
	if (m_Elapsed >= timestep)
	{
		//Update
		m_Player.Update();


		m_Elapsed -= timestep;
	}

	//~~~DEBUG OUTPUTS~~~//
	system("CLS");
	std::cout << "Time Elapsed: " << m_Elapsed << std::endl;
	std::cout << "Player Rotation: " << m_Player.GetRotation() << std::endl;
	std::cout << "Player xPos: " << m_Player.GetPos().x << std::endl;
	std::cout << "Player yPos: " << m_Player.GetPos().y << std::endl;
	std::cout << "Bullets: " << m_BulletList.size() << std::endl;
	std::cout << "Plater Xvelocity: " << m_Player.GetVelocity().x << std::endl;
	std::cout << "Plater Yvelocity: " << m_Player.GetVelocity().y << std::endl;

}

void Game::Render()
{
	m_Window.StartDraw();
	
	//Draw here
	m_Player.Render(*m_Window.GetRenderWindow());
	
	

	m_Window.EndDraw();
}