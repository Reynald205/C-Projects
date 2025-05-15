#include "Errors.h"
#include <iostream>
#include <SDL.h>
#include <cstdlib>
void FatalError(std::string errorstring)
{
	std::cout << errorstring << std::endl;
	std::cout << "Press any key to continue...." << std::endl;
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(69);
}