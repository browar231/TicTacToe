#pragma once
#include "Board.h"
#include "Player.h"
#include <string>
class PlayerConsole : public Player {
public:
	PlayerConsole(const std::string& name, char sign)
		: Player(name, sign) {};
	virtual ~PlayerConsole() = default;
	int provideField(const Board& board) const override;

private:
	int askForInput() const;
};