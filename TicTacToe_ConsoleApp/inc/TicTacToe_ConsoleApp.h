#pragma once
#include "TicTacToe.h"

class TicTacToe_ConsoleApp : public TicTacToe {

public:
	TicTacToe_ConsoleApp(const int numberOfHumanPlayers);
	static void intro();
	// overrides
	void printBoard() const override;
	void onBeforeStep(Player* currentPlayer) const override;
	void onInvalidMove() const override;
	void onWin(Player* currentPlayer) const override;
	void onDraw() const override;
	void onInput() const override;
};