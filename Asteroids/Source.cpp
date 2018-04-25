//Asteroids
//Asteroids clone in SFML

#include "Game.h"

int main()
{
	Game game;

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

	return 0;
}