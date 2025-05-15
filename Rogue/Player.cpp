#include "Player.h"
#include <random>
#include <ctime>
using namespace std;

//Constructor that sets player position to zero.
Player::Player()
{
	_x = 0;
	_y = 0;
}

//Initializes player with properties
void Player::init(int level, int health, int attack, int defense, int experience) 
{
	int _level = level;
	int _health = health;
	int _attack = attack;
	int _defense = defense;
	int _experience = experience;
}

//Sets the position of the player
void Player::setPosition(int x, int y) 
{
	_x = x;
	_y = y;
}

//Gets the position of the player using reference variables
void Player::getPosition(int &x, int &y) 
{
	x = _x;
	y = _y;
}

int Player::attack() 
{
	static default_random_engine rng(time(NULL));
	uniform_int_distribution<int> attackroll (0, _attack);
	return attackroll(rng);
}

void Player::addexp(int exp)
{
	_experience += exp;
	//Level Up!!!
	while ( _experience > 30)
	{
		printf("LEVELED UP!\n");
		_experience -= 30;
		_attack += 20;
		_defense += 15;
		_health += 50;
		_level++;
		system("PAUSE");
	}
}

int Player::damage(int attack)
{
	attack -= _defense;
	//Check if attack does damage.
	if (attack > 0)
	{
		_health -= attack;
		//Check if he died
		if (_health <= 0)
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}