//Reynald Walme - Program that uses random number generators. 
#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;


int main() 
{
	mt19937 rng(time(NULL)); //Sets up and names the RNG.
	uniform_int_distribution<int> diceroll(1, 6); //Sets Min, Max INTERGER of diceroll.
	uniform_real_distribution<float> attackroll(0.0f,1.0f);//Sets up float rng between 0-1.
	
	for (int i = 1; i < 6; i++)
	{
		cout << "I am rolling a : " << diceroll(rng) << endl;
	}
	
	for (int i = 1; i < 6; i++)
	{
		cout << "I am attacking snake : " << endl;
		float attack = attackroll(rng);
		
		if (attack <= 0.3f)
		{
			cout << "Yay I hit the snake" << endl;
		}
		else
		{
			cout << "Oh no I missed the snake" << endl;
		}
	}
	
	
	system("PAUSE");
	return 0;
}