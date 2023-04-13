#pragma once
#include "Players.h"
#include <memory>
#include <string>
#include <vector>
class TicTacToe {
public:
	typedef int PlayerID;
	TicTacToe();
	TicTacToe(const int numberOfHumanPlayers);
	bool isRunning();
	static void intro();
	static std::string getInputFromConsole();
	void terminate();
	void step();
	void clearConsole();
	void printBoard();

private:
	bool m_running { true };
	char m_board[9];
	bool m_allowed[9];
	std::vector<std::unique_ptr<Player>> m_players;
	PlayerID m_currentPlayer { 0 };
	bool isGameWon();
	bool isMoveAllowed(const int field);
	void nextPlayer();
	char returnPlayerSign(const PlayerID player);
	bool checkCol(const int);
	bool checkRow(const int);
	bool checkAllCols();
	bool checkAllRows();
	bool checkDiagonals();
	void initGame();
	void initializeAllowed();
	void initializeBoard();
	bool areThereFreeFields();
};