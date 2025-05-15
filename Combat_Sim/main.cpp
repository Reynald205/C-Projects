//Reynald Walme - Program that Sets up for Combat simulation. 
#include <iostream>
#include<string>
#include<random>
#include<ctime>
using namespace std;

int getnum_war();//Forward Declaration so program can read functions below int main, to work in int main
int getnum_col();//Forward Declaration so program can read functions below int main, to work in int main
void print_results(int num_colonizer, int num_warrior);
void sim_battle(int &num_warrior, int &num_colonizer);//Passby reference allows variables in main to be changed in functions.

int main(){
	
	int num_warrior; //Number of warriors
	int num_colonizer; //Number of colonizers
	
	cout << "******WARRIORS VS COLONIZERS******" << endl;	
	num_warrior = getnum_war();	
	num_colonizer = getnum_col();	
	cout << "\nBEGIN COMBAT!!!!" << endl;
	cout << "\n<EPIC COMBAT NOISES>\n"<<endl;
	sim_battle(num_warrior, num_colonizer);	
	print_results(num_colonizer, num_warrior);
	system("PAUSE");
	return 0;
}

int getnum_war() //Function to get number of warriors for the battle
{
	int num_warrior;//This is a seperate variable inside the function.
	cout << "Please enter the number of Brave Warriors for this Battle" << endl;
	cin >> num_warrior;
	return num_warrior;
}

int getnum_col() //Function to get number of colonizers for the battle
{
	int num_colonizer;//This is a seperate variable inside the function.
	cout << "Please enter the number of Evil Colonizers" << endl;
	cin >> num_colonizer;
	return num_colonizer;
}

void print_results(int num_colonizer,int num_warrior) // By using parameters this function uses the variable in int main.
{
	cout << "\n******THE BATTLE HAS BEEN DECIDED******\n" << endl;
	if (num_colonizer == 0)
	{
		cout << "******WARRIORS ARE VICTORIOUS !!!!******\n" << endl;
		cout << "With " << num_warrior << " warriors left and " << num_colonizer << " Colonizers left" << endl;
	}
	else
	{
		cout << "******COLONIZERS ARE VICTORIOUS !!!!******\n" << endl;
		cout << "With " << num_colonizer << " colonizers left and " << num_warrior << " warriors left" << endl;
	}
	cout << "\n******GAME OVER******\n" << endl;
}

void sim_battle(int &num_warrior,int &num_colonizer) 
{
	static mt19937 rng(time(NULL));//Sets up and names the RNG. Static insures the rng created will stay in case of repeated use. 
	uniform_int_distribution<int> diceroll(1, 6); //Sets Min, Max INTERGER of diceroll.
	uniform_real_distribution<float> attackroll(0.0f, 1.0f);//Sets up float rng between 0-1.
	int warrior_health = 100;
	int colonizer_health = 50;
	int warrior_attack = 25;
	int colonizer_attack = 20;

	while (num_warrior > 0 && num_colonizer > 0)
	{
		if (warrior_health > 0 && num_warrior > 0)
		{
			cout << "Warrior attacks" << endl;
			if (diceroll(rng) <= 1)
			{
				cout << "Warrior missed !!!" << endl;
			}
			else
			{
				colonizer_health = colonizer_health - warrior_attack;
				cout << "Colonizer took " << warrior_attack << " damage and HP is : " << colonizer_health << endl;
				if (colonizer_health == 0)
				{
					cout << "Colonizer has died" << endl;
					num_colonizer--;
					cout << num_colonizer << " Colonizers left" << endl;
					colonizer_health = 50;
				}
			}

		}

		if (colonizer_health > 0 && num_colonizer > 0)
		{
			cout << "Colonizer shoots" << endl;
			if (attackroll(rng) < 0.5f)
			{
				warrior_health = warrior_health - colonizer_attack;
				cout << "Warrior took " << colonizer_attack << " damage and HP is : " << warrior_health << endl;
				if (warrior_health == 0)
				{
					cout << "Warrior has died" << endl;
					num_warrior--;
					cout << num_warrior << " Warriors left" << endl;
					warrior_health = 100;
				}
			}
			else
			{
				cout << "Colonizer's gun misfired" << endl;
			}
		}
	}
	

}