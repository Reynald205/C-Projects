//Reynald Walme - Program that uses code from other files.
#include<iostream>
#include<string>
#include "Monster.h" //In order to use different files,you must include the header file in " ".
using namespace std;


int main() {
	Monster monsters[100];//Only way for array to work is to make anoter Monster fuction with no parameters.
	
	Monster Monster1("Fred");
	Monster Monster2("Apollo");
	Monster1.print_name();
	Monster2.print_name();

	monsters[0].print_name();
	
	system("PAUSE");
	return 0;
}