#pragma once
#include "Board.h"
#include "Player.h"
#include <array>
#include <memory>
#include <string>
#include <vector>
class TicTacToe {
public:
	TicTacToe()
		: m_invertPlayers(randomZeroOrOne()) {};
	void step();
	bool isRunning() const;
	void terminate();
	// for implementation
	virtual void printBoard() const {};
	virtual void onBeforeStep() const {};
	virtual void onInvalidMove() const {};
	virtual void onWin(Player* currentPlayer) const {};
	virtual void onDraw() const {};
	virtual void onInput() const {};

protected:
	bool m_running { true };
	const int m_invertPlayers;
	std::vector<std::unique_ptr<Player>> m_players;
	Board m_board;
	int randomZeroOrOne() const;
	int currentPlayerId() const;
};