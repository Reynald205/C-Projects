#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
using namespace std;

class Level
{
public:
	Level();
	void Loadlevel(string Filename,Player &player);
	void printlevel();
	void trymovePlayer(char input, Player &player);
	//Getters
	char getTile(int x, int y);
	//Setters
	void setTile(int x, int y, char tile);
private:
	vector <string> _levelData;
	vector <Enemy> _enemies;
	void processPlayerMove(Player &player, int targetx, int targety);
	void battle(Player &player, int targetx, int targety);
};

