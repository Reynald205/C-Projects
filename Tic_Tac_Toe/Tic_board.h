#pragma once
class Tic_board
{
public:
	Tic_board();
	void print_board();
	char set_mark(char turn);
	bool check_win(char turn);
	bool _done;
	bool Game_over();
	int x;
	int y;

private:
	char board[3][3];
	
};

