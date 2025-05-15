#include "MainGame.h"
#include "Errors.h"
#include<iostream>
#include<string>


MainGame::MainGame()
{
	_window = nullptr;
	_screenwidth = 1024;
	_screenheight = 768;
	_gamestate = GameState::PLAY;
}

MainGame::~MainGame()
{

}

void MainGame::run()
{
	initSystems();
	_sprite.init(-1.0f, -1.0f, 2.0f, 2.0f);
	gameloop();
}

void MainGame::initSystems()
{
	//Initializes the SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Graphics Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_screenwidth,_screenheight,SDL_WINDOW_OPENGL);
	if (_window == nullptr)
	{
		FatalError("SDL Window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		FatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		FatalError("Could not initialize GLEW!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	initShaders();
}

void MainGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.linkShaders();
}

void MainGame::gameloop() 
{
	while (_gamestate != GameState::EXIT)
	{
		processInput();
		drawgame();
	}
}

void MainGame::processInput() 
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt) == true) 
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gamestate = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
		
		
		}
	}
}

void MainGame::drawgame() 
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_colorProgram.use();
	_sprite.draw();
	_colorProgram.unuse();

	SDL_GL_SwapWindow(_window);
}

