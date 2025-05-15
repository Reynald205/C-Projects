//Reynald Walme - Program that creates a checkerboard on the screen.
#include<iostream>
#include<string>
using namespace std;

class Checkerboard
{
public:
	void init_board()
	{
		for (int y = 0; y < 8; y++)//for loop goes through the rows.
		{
			for (int x = 0; x < 8; x++)//for loop goes though the columns of the selected row 
			{
				if (((x + y) % 2) == 0)//Using X+Y will let the rows alternate like a real checkerboard.
				{
					board[y][x] = '.';
				}
				else
				{
					board[y][x] = '*';
				}
			}
		}
	}
	void print_board() 
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				cout << board[y][x];
			}
			cout << endl;
		}
	}
private:
	char board[8][8];
};

int main() 
{
		//For multi dimensional arrays rows[] first, then column[] second.
		//int player_ivt[2][6] = { { 0,0,0,0,0,0 },{ 0,0,0,0,0,0 } };
		
	Checkerboard board;
	board.init_board();
	board.print_board();

		system("PAUSE");
		return 0;
}
	
