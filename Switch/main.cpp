//Reynald Walme Program that uses the switch case function. 
#include <iostream>
#include <string>
using namespace std;

//ASCII Dungeon Game!

// ###########
// #.........#
// #..@...S..#
// #.........#
// ###########

/* 
(#) = walls (.) = air
(@) = player (S) = snake 
 */

int main() {
	char movespot = '.';

	if (movespot == '.')
	{
		printf("You can move!\n");
	}
	else if(movespot =='#')
	{
		printf("You can't move there!\n");
	}
	else if (movespot == 'S') 
	{
		printf("Time for battle! \n");
	}

	switch (movespot)
{
	case '.':
			printf("You can move!\n");
			break;
	case '#':
			printf("You can't move there!\n");
			break;
	case 'S':
			printf("Time for battle! \n");
			break;
	default:
		break;
}


	system("PAUSE");
	return 0;
}