#pragma once
#include "Players.h"
#include <string>
class TicTacToe {
public:
	typedef int PlayerID;
	TicTacToe();
	TicTacToe(Player*, Player*);
	TicTacToe(int numberOfHumanPlayers);
	bool isRunning();
	static void intro();
	static std::string getInputFromConsole();
	void terminate();
	void step();
	void printBoard();

private:
	bool m_running { true };
	char m_board[9];
	bool m_allowed[9];
	Player* m_players[2];
	PlayerID m_currentPlayer { 0 };
	bool isGameWon();
	bool checkCol(int);
	bool checkRow(int);
	bool checkAllCols();
	bool checkAllRows();
	bool checkDiagonals();
	void initGame();
	void initializeAllowed();
	void initializeBoard();
	bool areThereFreeFields();
};