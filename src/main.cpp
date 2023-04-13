#include "TicTacToe.h"
#include <iostream>
int main()
{
	int players;
	std::cout << "0 - two CPU players" << std::endl
			  << "1 - play with CPU" << std::endl
			  << "2 - two players" << std::endl;
	std::cin >> players;
	do {
		TicTacToe game(players);
		game.clearConsole();
		game.printBoard();
		game.intro();
		while (game.isRunning()) {
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