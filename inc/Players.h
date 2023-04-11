#pragma once
#include <string>
class Player {
public:
	Player(std::string name)
		: m_name(name) {};
	virtual int move(bool allowed[9]) = 0;
	std::string getName();

private:
	std::string m_name;
};
// Human player
class PlayerHuman : public Player {
public:
	PlayerHuman()
		: Player("Human #" + std::to_string(s_id++)) {};
	int move(bool allowed[9]) override;

private:
	static int s_id;
	int askForInput();
};
// CPU Player
class PlayerCPU : public Player {
public:
	PlayerCPU()
		: Player("CPU #" + std::to_string(s_id++)) {};
	int move(bool allowed[9]) override;

private:
	static int s_id;
};