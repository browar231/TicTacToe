#pragma once
#include "Board.h"
#include <array>
#include <string>
enum class PlayerCPU_strategy {
	FirstAllowed, // first from allowed moves
	Random, // random allowed move
	WinIfPossible, // cpu will make random move, but won't miss winning moves
	WinOrBlock // like the one before, but when no winning move is possible, cpu will try blocking opponent
};
class Player {
public:
	Player(const std::string& name, char sign)
		: m_name(name)
		, m_sign(sign) {};
	virtual int provideField(const Board& board) const = 0;
	const std::string& getName() const;
	char getSign() const;

protected:
	char returnOpponentSign() const;
	const char m_sign;
	const std::string m_name;
};
// Human player
class PlayerHuman : public Player {
public:
	PlayerHuman(const std::string& name, char sign)
		: Player(name, sign) {};
	int provideField(const Board& board) const override;

private:
	int askForInput() const;
};
// CPU Player
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

private:
	PlayerCPU_strategy m_strategy;
};