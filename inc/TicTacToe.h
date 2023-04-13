#pragma once
#include "Board.h"
#include "Players.h"
#include <array>
#include <memory>
#include <string>
#include <vector>
class TicTacToe {
public:
	TicTacToe();
	TicTacToe(const int numberOfHumanPlayers);
	static void intro();
	static std::string getInputFromConsole();
	void terminate();
	void step();
	void clearConsole();
	void printBoard();
	bool isRunning();

private:
	bool m_running { true };
	std::vector<std::unique_ptr<Player>> m_players;
	int m_currentPlayer { 0 };
	Board m_board;
	void nextPlayer();
	char returnPlayerSign(const int player);
};