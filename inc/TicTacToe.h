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
	void printBoard() const;
	void step();
	bool isRunning() const;
	void terminate();

private:
	bool m_running { true };
	std::vector<std::unique_ptr<Player>> m_players;
	Board m_board;
	int currentPlayerId();
	char returnPlayerSign(const int player) const;
};