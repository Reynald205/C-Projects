//Reynald Walme - Program that uses vectors.
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main() 
{
	string shop_items_names[4] = {"Swords","Spears","Axes","Guns"};
	list <string> shop_items;
	vector <string> item_names;    //How a vector is called.
	
	cout << "It is "<< item_names.size() << " spaces long." << endl;
	item_names.push_back("Gloves");//Adds to the back of the list. Push
	item_names.push_back("Hats");
	item_names.push_back("Armor");
	item_names.push_back("Boots");

	item_names.pop_back();          //Removes the last item 

	for (int i = 0; i < item_names.size(); i++)
	{
		cout << item_names[i] << endl;
	}

	cout << "It is " << item_names.size() << " spaces long now." << endl;
	cout << "\n******************************\n" << endl;
	
	shop_items.push_back("Gloves");
	shop_items.push_front("Axes");
	shop_items.push_back("Swords");
	shop_items.push_back("Guns");
	shop_items.push_back("Spears");

	list <string>::iterator  shop; //For a list the for loop can't be used so an iterator is called instead.
	for (shop = shop_items.begin();shop != shop_items.end(); shop++)//For loop with the list iterator.
	{
		cout << *shop << endl;
	}
	cout << "\n******************************\n" << endl;
	
	shop_items.remove("Guns"); //Removes item from list.

	for (shop = shop_items.begin();shop != shop_items.end(); shop++)//For loop with the list iterator.
	{
		cout << *shop << endl;
	}

	system("PAUSE");
	return 0;

}