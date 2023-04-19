#pragma once
#include "TicTacToe.h"

class TicTacToeConsoleApp : public TicTacToe {

public:
	using TicTacToe::TicTacToe;
	static void intro();
	// overrides
	void printBoard() const override;
	void onBeforeStep() const override;
	void onInvalidMove() const override;
	void onWin() const override;
	void onDraw() const override;
	void onInput() const override;
};