/*Reynald Walme - Program to show little kids the times table*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double leet;

	cout << "Please enter the number who's times table up to ten you would like to see" << endl;
	cin >> leet;
	if (leet > 0)
	{
		for (int i = 1; i < 11; i++)
		{
			cout << leet << " times " << i << " is equal to : " << leet * i << endl;
		}
		
		cout << "The multples of " << leet << " up to 100 are:" << endl;
		for (int i = 0; i <= 100; i += leet)
		{
			cout << i << endl;
		}
	}
	
	else if (leet== 0) 
	{
		cout << "Anything times 0 is 0." << endl;
	}
	
	else
	{
		cout << "Enter a real number smart guy....." << endl;
	}
	
	
	system("PAUSE");
	return 0;
	}