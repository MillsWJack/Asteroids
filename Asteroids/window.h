#pragma once
#include <SFML\Graphics.hpp>
class window
{
public:
	window(sf::Vector2u size, std::string m_Title);
	~window();

	inline bool IsDone() { return m_IsDone; }
	sf::RenderWindow* GetRenderWindow() { return &m_RenderWindow; }

	void Create();
	void Update();
	void Destroy();
	void StartDraw();
	void EndDraw();
	void Render(sf::Drawable& drawable);

private:
	sf::RenderWindow m_RenderWindow;
	const sf::Vector2u m_Size;

	const std::string m_Title;

	bool m_IsDone;
};

