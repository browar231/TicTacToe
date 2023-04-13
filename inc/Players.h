#pragma once
#include "Board.h"
#include <array>
#include <string>
class Player {
public:
	Player(std::string name)
		: m_name(name) {};
	virtual int provideField(Board& board) = 0;
	std::string getName();

private:
	const std::string m_name;
};
// Human player
class PlayerHuman : public Player {
public:
	PlayerHuman()
		: Player("Player #" + std::to_string(s_id++)) {};
	PlayerHuman(std::string name)
		: Player(name) {};
	int provideField(Board& board) override;

private:
	static int s_id;
	int askForInput();
};
// CPU Player
class PlayerCPU : public Player {
public:
	PlayerCPU()
		: Player("CPU #" + std::to_string(s_id++)) {};
	PlayerCPU(std::string name)
		: Player(name) {};
	int provideField(Board& board) override;
	int returnFirstAllowedField(Board& board);
	int returnRandomField(Board& board);

private:
	static int s_id;
};