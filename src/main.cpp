#include "TicTacToe.h"
#include <iostream>
int main()
{
	int playersAmount;
	std::cout << "0 - two CPU players\n"
			  << "1 - play with CPU\n"
			  << "2 - two players\n";
	std::cin >> playersAmount;
	TicTacToe::intro();
	do {
		TicTacToe game(playersAmount);
		game.clearConsole();
		game.printBoard();
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