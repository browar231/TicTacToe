#pragma once
#include "TicTacToe.h"

class ConsoleApp : public TicTacToe {

public:
	using TicTacToe::TicTacToe;
	static void intro();
	// overrides
	void printBoard() const override;
	void onBeforeStep() const override;
	void onInvalidMove() const override;
	void onWin(Player* currentPlayer) const override;
	void onDraw() const override;
	void onInput() const override;
};