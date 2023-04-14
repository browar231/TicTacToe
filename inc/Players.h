#pragma once
#include "Board.h"
#include <array>
#include <string>
class Player {
public:
	Player(const std::string& name)
		: m_name(name) {};
	virtual int provideField(const Board& board) const = 0;
	const std::string& getName() const;

private:
	const std::string m_name;
};
// Human player
class PlayerHuman : public Player {
public:
	PlayerHuman(const std::string& name)
		: Player(name) {};
	int provideField(const Board& board) const override;

private:
	int askForInput() const;
};
// CPU Player
class PlayerCPU : public Player {
public:
	PlayerCPU(const std::string& name)
		: Player(name) {};
	int provideField(const Board& board) const override;
	int returnFirstAllowedField(const Board& board) const;
	int returnRandomField(const Board& board) const;
};