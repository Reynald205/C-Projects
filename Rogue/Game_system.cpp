#include "Game_system.h"
#include <iostream>
#include <conio.h>

//Constructor sets up the game.
Game_system::Game_system(string levelFile)
{
	_player.init(1,100,10,10,0);
	_level.Loadlevel(levelFile, _player);
	_level.printlevel();
	system("PAUSE");
}

void Game_system::playgame() //Loops thru the game
{
	bool isDone = false;

	while (isDone != true)
	{
		_level.printlevel();
		playerMove();
	}
}
void Game_system::playerMove() 
{
	char input;
	cout << "Enter a move command (w/a/s/d)" << endl;
	input = _getch();
	_level.trymovePlayer(input, _player);
}