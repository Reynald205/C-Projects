#include "Tic_board.h"
#include <iostream>
#include <string>
using namespace std;



Tic_board::Tic_board()
{
	for (int y = 0; y < 3; y++)//for loop goes through the rows.
	{
		for (int x = 0; x < 3; x++)//for loop goes though the columns of the selected row 
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

void Tic_board::print_board()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				cout <<"|_"<< board[y][x]<<"_|";
			}
			cout << endl;
		}
	}

char Tic_board::set_mark(char turn) 
{
	cout << "It is Player: " << turn << "turn" << endl;
	cout << "Please enter the X-axis coordinates (0-2) you want to mark "<< turn << endl;
	cin >> x;
	cout << "Please enter the Y-axis coordinates (0-2) you want to mark " << turn << endl;
	cin >> y;
	if (x > 2 || y > 2)
	{
		cout << "Invalid coordinates......\nTry again!!!" << endl;
		return turn;
	}
	else if (board[y][x]=='X'||board[y][x]=='O')
	{
		cout << "That spot is already marked...\nTry another space!!!" << endl;
		return turn;
	}
	else
	{
		board[y][x] = turn;
		_done = check_win(turn);
		if (turn =='X')
		{
			turn = 'O';
			return turn;
		}
		if (turn == 'O')
		{
			turn = 'X';
			return turn;
		}
	}
}

bool Tic_board::check_win(char turn) 
{	
	for (int y = 0; y < 3; y++)//for loop goes through the rows.
	{
		for (int x = 0; x < 3; x++)//for loop goes though the columns of the selected row 
		{
			if (board[y][x] == turn && board [(y+1)][(x+1)]==turn && board[(y + 2)][(x + 2)] == turn)
			{
				cout << "\nPlayer: " << turn << " is the winner!!!" << endl;
				return true;
			}
			else if (board[y][x] == turn && board[(y -1)][(x + 1)] == turn && board[(y - 2)][(x + 2)] == turn)
			{
				cout << "\nPlayer: " << turn << " is the winner!!!" << endl;
				return true;
			}
			else if (board[y][x] == turn && board[y][(x + 1)] == turn && board[y][(x + 2)] == turn)
			{
				cout << "\nPlayer: " << turn << " is the winner!!!" << endl;
				return true;
			}
			else if (board[y][x] == turn && board[y][(x - 1)] == turn && board[y][(x - 2)] == turn)
			{
				cout << "\nPlayer: " << turn << " is the winner!!!" << endl;
				return true;
			}
			else if (board[y][x] == turn && board[(y + 1)][x] == turn && board[(y+2)][x] == turn)
			{
				cout << "\nPlayer: " << turn << " is the winner!!!" << endl;
				return true;
			}
			else if (board[y][x] == turn && board[(y-1)][x] == turn && board[(y-2)][x] == turn)
			{
				cout << "\nPlayer: " << turn << " is the winner!!!" << endl;
				return true;
			}
			else if (board[y][x] =='*'||board[y][x] =='.')
			{			
				return false;
			}
			else
			{
				cout << "\nDraw Game!!!!\nThanks For Playing!!!!" << endl;
				return true;
			}
		}
	}
}

bool Tic_board::Game_over()
{
		return _done;	
}