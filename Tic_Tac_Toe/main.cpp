//Reynald Walme - Program that allows you to play the game Tic Tac Toe.
#include <iostream>
#include "Tic_board.h"
#include <string>
using namespace std;
bool done = false;
char turn = 'X';

int main()
{
	//For multi dimensional arrays rows[] first, then column[] second.
	//int player_ivt[2][6] = { { 0,0,0,0,0,0 },{ 0,0,0,0,0,0 } };
	Tic_board board;
	
	while (done == false)
	{
		board.print_board();
		turn = board.set_mark(turn);
		done = board.Game_over();

	}

	system("PAUSE");
	return 0;
}