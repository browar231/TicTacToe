#pragma once
#include "Player.h"
enum class PlayerCPU_strategy {
	FirstAllowed, // first from allowed moves
	Random, // random allowed move
	WinIfPossible, // cpu will make random move, but won't miss winning moves
	WinOrBlock, // like the one before, but when no winning move is possible, cpu will try blocking opponent
	BeastMode // if i implemented it correctly, cpu won't lose
};

class PlayerCPU : public Player {
public:
	PlayerCPU(const std::string& name, char sign, PlayerCPU_strategy strategy)
		: Player(name, sign)
		, m_strategy(strategy) {};
	int provideField(const Board& board) const override;
	int returnFirstAllowedField(const Board& board) const;
	int returnRandomField(const Board& board) const;
	int returnWinningOrRandom(const Board& board) const;
	int returnWinningOrBlocking(const Board& board) const;
	int returnBestMove(const Board& board) const;

private:
	PlayerCPU_strategy m_strategy;
};