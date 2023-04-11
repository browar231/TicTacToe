#include "Players.h"
#include "TicTacToe.h"
#include <iostream>
#include <stdlib.h>
int main()
{
	int players;
	std::cout << "0 - play with CPU" << std::endl
			  << "1 - two players" << std::endl
			  << "2 - two CPU players" << std::endl;
	std::cin >> players;
	Player *player1, *player2;
	switch (players) {
	case 0:
		player1 = new PlayerHuman;
		player2 = new PlayerCPU;
		break;
	case 1:
		player1 = new PlayerHuman;
		player2 = new PlayerHuman;
		break;
	case 2:
		player1 = new PlayerCPU;
		player2 = new PlayerCPU;
		break;
	default:
		player1 = new PlayerHuman;
		player2 = new PlayerCPU;
	}
	TicTacToe game(player1, player2);
	game.intro();
	while (game.isRunning()) {
		system("clear");
		game.printBoard();
		game.step();
	}
}