#include "Game.h"

Game::Game():
	m_Window(sf::Vector2u(1920,1080), "Asteroids")
{
}

Game::~Game()
{
}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_Window.Update();
}

void Game::Render()
{
	m_Window.StartDraw();
	
	//Draw here

	m_Window.EndDraw();
}