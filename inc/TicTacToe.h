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
	void step();
	bool isRunning() const;
	void terminate();
	// for implementation
	virtual void printBoard() const {};
	virtual void onBeforeStep() const {};
	virtual void onInvalidMove() const {};
	virtual void onWin() const {};
	virtual void onDraw() const {};
	virtual void onInput() const {};

protected:
	bool m_running { true };
	std::vector<std::unique_ptr<Player>> m_players;
	Board m_board;
	int currentPlayerId() const;
};