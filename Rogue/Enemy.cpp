#include "Enemy.h"
#include <random>
#include <ctime>

Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int exp)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_exp = exp;
}

//Sets the enemy position
void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//Gets the position of the enemy using reference variables
void Enemy::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

string Enemy::getname() 
{ 
	return _name;
}

int Enemy::attack()
{
	static default_random_engine rng(time(NULL));
	uniform_int_distribution<int> attackroll(0, _attack);
	return attackroll(rng);
}

int Enemy::damage(int attack)
{
	attack -= _defense;
	//Check if attack does damage.
	if (attack > 0)
	{
		_health -= attack;
		//Check if he died
		if (_health <= 0)
		{
			return _exp;
		}
	}
	else
	{
		return 0;
	}
}