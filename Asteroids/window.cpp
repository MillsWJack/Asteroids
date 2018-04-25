#include "window.h"

window::window(sf::Vector2u size, const std::string title):
	m_Size(size),
	m_Title(title)
{
	Create();
}

window::~window()
{
}

void window::Create()
{
	m_RenderWindow.create({ m_Size.x, m_Size.y }, m_Title);
	m_RenderWindow.setFramerateLimit(60);
}

void window::Update()
{
	sf::Event event;
	while (m_RenderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed 
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_IsDone = true;
		}
	}
}

void window::Destroy()
{
	m_RenderWindow.close();
}

void window::StartDraw()
{
	m_RenderWindow.clear(sf::Color::Black);
}

void window::EndDraw()
{
	m_RenderWindow.display();
}

void window::Render(sf::Drawable& drawable)
{
	m_RenderWindow.draw(drawable);
}