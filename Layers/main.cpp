//Reynald Walme - Program to show how class functions work.
#include <iostream>
#include <string>
using namespace std;

class Colonizer //When class is made anything inside is automatically private.
{ 
public://Declares the shout function as public.
	void shout()
	{
		cout << "Lets group up and fight the rebels." << endl;
	}
	void set_name(string name) //Setter function.
	{
		_name = name;
	}
	string get_name() 
	{
		return _name;
	}
private:
	string _name;//Adding an _ before a private variable name is good programming practice for easy reading.
};



int main() 
{
	Colonizer enemy1;
	enemy1.set_name("George");
	enemy1.shout();
	cout <<"Colonizer " <<enemy1.get_name() << " attacks!"<< endl;

	system("PAUSE");
	return 0;
}