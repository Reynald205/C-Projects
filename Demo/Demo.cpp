/*Reynald Walme - Demo Program to shake off the rust*/ 
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double leet = 0;
	string name;
	
	cout << "Please enter a name" << endl;
	cin >> name;
	cout << "Your name is: "<< name <<" and it is "<< name.length() <<" letters long"<< endl;
	cout << "Please enter a number" << endl;
	cin >> leet;
	if (leet>= 9001)
	{
		cout << "Hello World " << leet << "\n" << "It's over 9000!" << endl;
	}
	else if (leet== 69)
	{
		cout << "Haha Waifu 21" << endl;
	}
	else
	{
		cout << "What are you, Yamcha?" << endl;
	}
	
	
	system("pause");
	return 0;
}