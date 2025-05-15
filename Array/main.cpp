//Reynald Walme - Program that uses arrays to create an Item shop.
#include <iostream>
#include <string>
using namespace std;

const int num_items = 4; //Arrays only work with constant numbers so using const ensures that value is never changed.
const string shop_items[num_items] = { "Swords","Spears","Axes","Guns" };
void print_shop();
void print_Inventory(int player_items[num_items]);
bool buy_items(int player_items[num_items]);//Passby ref doesn't work on arrays because arrays already work by ref.


int main() {
	bool done = false;
	int player_items[num_items] = {1,4,6,1};
	while (done == false)
	{
		print_shop();
		print_Inventory(player_items);
		done = buy_items(player_items);
		cout << "\n\n\n" << endl;
	}	
	
	system("PAUSE");
	return 0;
}

void print_Inventory(int player_items[num_items])
{
	cout << "Your current Inventory includes:\n" << endl;
	for (int i = 0; i < num_items; i++)
	{
		if (player_items[i] > 0)
		{
			cout << player_items[i] << " x "<< shop_items[i]<< endl;
		}
	}
	cout << endl;
}

void print_shop()
{
	cout << "******WELCOME TO THE ITEM SHOP******\n" << endl;
	for (int i = 0; i < num_items; i++)
	{
		cout << i+1 <<". "<< "We are selling " << shop_items[i] << " at our store." << endl;
	}
	cout << "\n***********************************\n" << endl;
}

bool buy_items(int player_items[num_items])//Returns a bool in order to keep going or end the program. 
{
	int select;
	cout << "Heh Heh, What Are Ya Buyin' Strangjah\n" << endl;
	cout << "Use numbers 1 thru "<<num_items <<" to select your item and enter 0 to leave." << endl;
	cin >> select;
	if (select <= num_items && select > 0)
	{
		player_items[select - 1]++;
		return false;
	}
	if (select == 0)
	{
		cout << "\nHeh Heh, Thank You For Shopping With Us." << endl;
		return true;
	}
	else
	{
		cout << "Sorry don't have that in stock yet...." << endl;
		return false;
	}
}