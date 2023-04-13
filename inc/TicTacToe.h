#pragma once
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
	std::array<char, 9> m_board;
	std::array<bool, 9> m_allowed;
	std::vector<std::unique_ptr<Player>> m_players;
	int m_currentPlayer { 0 };
	void initGame();
	void initializeAllowed();
	void initializeBoard();
	bool isGameWon();
	bool isMoveAllowed(const int field);
	bool areThereFreeFields();
	bool checkCol(const int);
	bool checkRow(const int);
	bool checkAllCols();
	bool checkAllRows();
	bool checkDiagonals();
	void takeFieldOnBoard(const int field, const char sign);
	void nextPlayer();
	char returnPlayerSign(const int player);
};