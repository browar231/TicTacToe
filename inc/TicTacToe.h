#pragma once
#include "Players.h"
#include <string>
class TicTacToe {
public:
	typedef int PlayerID;
	TicTacToe();
	TicTacToe(const int numberOfHumanPlayers);
	~TicTacToe();
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
	Player* m_players[2];
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