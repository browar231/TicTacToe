#pragma once
#include <string>
class Player {
public:
	Player(std::string name)
		: m_name(name) {};
	virtual int move(const bool allowed[9]) = 0;
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
	int move(const bool allowed[9]) override;

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
	int move(const bool allowed[9]) override;
	int moveFirstAllowed(const bool allowed[9]);
	int moveRandom(const bool allowed[9]);

private:
	static int s_id;
};