#include "TicTacToe.h"
#include <iostream>
#include <stdlib.h>
int main()
{
	int players;
	std::cout << "0 - two CPU players" << std::endl
			  << "1 - two players" << std::endl
			  << "2 - play with CPU" << std::endl;
	std::cin >> players;

	TicTacToe game(players);
	game.intro();
	while (game.isRunning()) {
		system("clear");
		game.printBoard();
		game.step();
	}
}