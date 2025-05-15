//Reynald Walme -> Program that makes a game engine.
#include "SDL.h"
#include "Game.h"
#include<iostream>
using namespace std;

Game *game = nullptr;

int main (int argc, char* argv[]) 
{
	const int FPS = 60;
	const int framedelay = 1000 / FPS;
	
	Uint32 framestart;
	int frametime;
	
	game = new Game();
	game->init("Haitian RPG",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running())
	{
		framestart = SDL_GetTicks();
		
		game->handleEvents();
		game->update();
		game->render();

		frametime = SDL_GetTicks() - framestart;

		if (framedelay > frametime)
		{
			SDL_Delay(framedelay - frametime);
		}

	}
	game->clean();

	return 0;
}