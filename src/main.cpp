#include "Console.h"
#include "ConsoleApp.h"
#include <iostream>
int main()
{
	int playersAmount;
	Console::clear();
	ConsoleApp::intro();
	Console::getInputUntilSuccess(playersAmount);
	if (playersAmount < 0 || playersAmount > 2) {
		return EXIT_SUCCESS;
	}
	do {
		ConsoleApp game(playersAmount);
		game.printBoard();
		while (game.isRunning()) {
			game.step();
		};
		int continuation;
		std::cout << "Play again?\n"
				  << "1 - yes\n"
				  << "0 - no\n";
		Console::getInputUntilSuccess(continuation);

		if (continuation == 0) {
			break;
		}
	} while (true);
}