//Reynald Walme -->  Program that shows off the basics of inheritance and polymorphism.
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Monster { //Basic template for Monsters
public:
	Monster() 
	{
		_name = "NONAME";
	}
	
	Monster(string name) 
	{	
		_name = name;
	}
	
	void attack() 
	{
		cout << _name << " is attacking!\n";
	}
	
	void move() 
	{
		cout << _name << " is moving!\n";
	}

	virtual void update() //Virtual is needed so other inherited classes can overwrite its function.
	{
		cout << "Empty Update." << endl;
	}

protected: //Same as private but inheriting classes can access data.
	string _name;
};

class Spider : public Monster //How you inherit, Spider is now a sub-class of Monster, taking all its traits and functions.
{
public:
	Spider(string name)
	{
		_name = name;
	}
	
	void climb() //You can add new functions that are unique to the inherited class.
	{
		cout<< _name <<" is climbing the walls"<<endl;
	}
	
	void update()
	{
		attack();
		move();
		climb();
	}
};

class Goblin : public Monster 
{
public:
	Goblin(string name)
	{
		_name = name;
	}

	void steal() 
	{
		cout << _name << " is trying to steal items" << endl;
	}
	
	void update()
	{
		attack();
		move();
		steal();
	}
};

int main() {
	list <Monster*> monsters;
	list <Monster*>::iterator mit;

	Monster monster("Bandit");
	Spider spider("Bob");
	Goblin goblin("Kichi");
	
	monsters.push_back(&monster);
	monsters.push_back(&spider);
	monsters.push_back(&goblin);
	
	bool isDone = false;
	while (isDone == false)
	{
		for (mit = monsters.begin(); mit != monsters.end(); mit ++)
		{
			(*mit)->update();
		}
		isDone = true;
	}

	/*monster.move();
	monster.attack();
	spider.update();
	goblin.update();*/
	
	int a;
	cout << "Enter any button to continue..." << endl;
	cin >> a;
}