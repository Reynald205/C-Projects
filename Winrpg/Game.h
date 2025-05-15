#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width , int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

private:
	bool isrunning;
	int count = 0;
	SDL_Window *window;
	SDL_Renderer *renderer;
};
