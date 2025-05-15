#pragma once
#include <string>
using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level,int attack, int defense, int health, int exp);
	int attack();
	int damage(int attack);
	//Setters
	void setPosition(int x, int y);

	//Getters
	void getPosition(int &x, int &y);
	string getname();
private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defense;
	int _health;
	int _exp;

	//Position
	int _x;
	int _y;
};

