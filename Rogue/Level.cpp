#include "Level.h"
#include <iostream>
#include <fstream>
#include <cstdio>


Level::Level()
{

}

void Level::Loadlevel(string Filename, Player &player)
{	//Loads the level
	ifstream file;
	file.open(Filename);
	if (file.fail())
	{
		perror(Filename.c_str());
		system("PAUSE");
		exit(1);//this will quit the whole game.
	}
	
	string line;
	
	while (getline(file, line))
	{
		_levelData.push_back(line);
	}
	file.close();
	
	// Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++)
	{
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];
			switch (tile)
			{
			case '@': // Player
				player.setPosition(j,i);
				break;
			case 'S': // Snake
				_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
				_enemies.back().setPosition(j, i);
				break;
			case 'g': // Goblin
				_enemies.push_back(Enemy("Goblin", tile, 2, 5, 5, 20, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'B': // Bandit
				_enemies.push_back(Enemy("Bandit", tile, 3, 7, 7, 40, 100));
				_enemies.back().setPosition(j, i);
				break;
			case 'O': // Ogre
				_enemies.push_back(Enemy("Ogre", tile, 5, 15, 10, 80, 500));
				_enemies.back().setPosition(j, i);
				break;
			case 'D': // Dragon
				_enemies.push_back(Enemy("Dragon", tile, 7, 25, 20, 150, 1000));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}

}

void Level::printlevel()
{
	cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::trymovePlayer(char input, Player &player) 
{
	int playerx;
	int playery;
	player.getPosition(playerx, playery);

	switch (input)
	{
	case 'w'://Up
	case 'W':
		processPlayerMove(player, playerx, playery - 1);
		break;
	case 'a'://Left
	case 'A':
		processPlayerMove(player, playerx -1, playery);
		break;
	case 's'://Down
	case 'S':
		processPlayerMove(player, playerx, playery + 1);
		break;
	case 'd'://Right
	case 'D':
		processPlayerMove(player, playerx + 1, playery);
		break;
	default:
		cout << "Invalid Input" << endl;
		system("PAUSE");
		break;
	}
}

char Level::getTile(int x, int y) 
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) 
{
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetx, int targety)
{
	int playerx;
	int playery;
	player.getPosition(playerx, playery);

	char moveTile = getTile(targetx, targety);
	switch (moveTile)
	{
	case '#':
		printf("You ran into a Wall\n");
		break;
	case'.':
		player.setPosition(targetx, targety);
		setTile(playerx, playery, '.');
		setTile(targetx, targety, '@');
		break;
	default:
		battle(player, targetx, targety);
		break;
	}
}

void Level::battle(Player &player, int targetx, int targety)
{
	int enemy_x;
	int enemy_y;
	int attackRoll;
	int result;
	string enemy_name;

	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemy_x, enemy_y);
		enemy_name = _enemies[i].getname();
		if (targetx == enemy_x && targety == enemy_y)
		{
			//Battle
			attackRoll = player.attack();
			printf("Player attacked %s with a roll of: %d", enemy_name.c_str(), attackRoll);
			result = _enemies[i].damage(attackRoll);
			if (result !=0)
			{
				setTile(targetx, targety, '.');
				printlevel();
				printf("Monster Died!");
				system("PAUSE");
				player.addexp(result);
				
				return;
			}
			//Monster turn
			attackRoll = _enemies[i].attack();
			printf("%s attacked Player with a roll of: %d", enemy_name.c_str(), attackRoll);
			result = player.damage(attackRoll);
			if (result != 0)
			{
				setTile(targetx, targety, 'X');
				printlevel();
				printf("You Died!");
				system("PAUSE");
				exit(0);
			}
			return;
		}
	}
}