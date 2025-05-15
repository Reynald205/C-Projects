//Reynald Walme -> Program that teaches the basics of windows and graphics
#include <windows.h>
#include "SDL.h"
#include <GL/glew.h>
#include "MainGame.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) 
{
	MainGame maingame;
	maingame.run();

	return 0;
}