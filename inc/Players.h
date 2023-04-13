#pragma once
#include <array>
#include <string>
class Player {
public:
	Player(std::string name)
		: m_name(name) {};
	virtual int provideField(const std::array<bool, 9>& allowed) = 0;
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
	int provideField(const std::array<bool, 9>& allowed) override;

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
	int provideField(const std::array<bool, 9>& allowed) override;
	int returnFirstAllowedField(const std::array<bool, 9>& allowed);
	int returnRandomField(const std::array<bool, 9>& allowed);

private:
	static int s_id;
};