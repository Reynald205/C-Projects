#include "Game.h"
using namespace std;


int main()
{
	srand(time(NULL));
	Game game;
	while (game.getplaying() )
	{
		game.main_menu();
	}

	return 0;

}