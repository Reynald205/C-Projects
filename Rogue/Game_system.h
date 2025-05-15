#pragma once
#include "Player.h"
#include "Level.h"
#include <string>
using namespace std; 

class Game_system
{
public:
	Game_system(string levelFile);
	void playgame();
	void playerMove();
private:
	Player _player;
	Level _level;
};

