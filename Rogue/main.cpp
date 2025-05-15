#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "Game_system.h"
using namespace std;

int main() {
	Game_system gamesystem("Level1.txt");
	gamesystem.playgame();




	system("PAUSE");
	return 0;
}