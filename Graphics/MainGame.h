#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include "Sprite.h"
#include "GLSLProgram.h"


enum class GameState {PLAY, EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();
	void run();
	
private:
	void initSystems();
	void initShaders();
	void gameloop();
	void processInput();
	void drawgame();
	SDL_Window* _window;
	int _screenwidth;
	int _screenheight;
	GameState _gamestate;

	Sprite _sprite;
	GLSLProgram _colorProgram;
};

