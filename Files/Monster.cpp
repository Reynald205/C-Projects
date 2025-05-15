#include "Monster.h"
#include <iostream>

//This is the constructor.
Monster::Monster() //As long as it two different parameters it counts as two different functions.
{
	_name = "NONAME";

}

Monster::Monster(string name)//Monster :: is to tell the compiler what class the function belongs to. 
{
	_name = name;
}

void Monster::print_name() 
{
	cout <<"My name is " << _name << endl;

}