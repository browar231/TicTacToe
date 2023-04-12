#include "TicTacToe.h"
#include <iostream>
#include <stdlib.h>
int main()
{
	int players;
	std::cout << "0 - two CPU players" << std::endl
			  << "1 - play with CPU" << std::endl
			  << "2 - two players" << std::endl;
	std::cin >> players;
	do {
		TicTacToe game(players);
		game.intro();
		while (game.isRunning()) {
			system("clear");
			game.printBoard();
			game.step();
		};
		char input;
		std::cout << "Play again?(y/n)";
		std::cin >> input;
		if (input != 'y') {
			break;
		}
	} while (true);
}