#pragma once
#include <string>
using namespace std;

class Monster
{
public:
	Monster();
	Monster(string name);//For constructors when called they execute their code, and no type (void int string) is neccessary.
	void print_name();


private:
	string _name;
	
};

