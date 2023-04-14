#pragma once
#include "Board.h"
#include <array>
#include <string>
class Player {
public:
	Player(std::string name)
		: m_name(name) {};
	virtual int provideField(const Board& board) = 0;
	std::string getName();

private:
	const std::string m_name;
};
// Human player
class PlayerHuman : public Player {
public:
	PlayerHuman(std::string name)
		: Player(name) {};
	int provideField(const Board& board) override;

private:
	int askForInput();
};
// CPU Player
class PlayerCPU : public Player {
public:
	PlayerCPU(std::string name)
		: Player(name) {};
	int provideField(const Board& board) override;
	int returnFirstAllowedField(const Board& board);
	int returnRandomField(const Board& board);
};