#pragma once
#include "Board.h"
#include "Players.h"
#include <array>
#include <memory>
#include <string>
#include <vector>
class TicTacToe {
public:
	TicTacToe(const int numberOfHumanPlayers);
	static void intro();
	static std::string getInputFromConsole();
	static void clearConsole();
	void printBoard();
	void step();
	bool isRunning();
	void terminate();

private:
	bool m_running { true };
	int m_currentPlayer { 0 };
	std::vector<std::unique_ptr<Player>> m_players;
	Board m_board;
	void nextPlayer();
	char returnPlayerSign(const int player);
};