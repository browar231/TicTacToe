#pragma once
#include "Player.h"
class PlayerGUI : public Player {
	PlayerGUI(const std::string& name, char sign)
		: Player(name, sign) {};
	virtual ~PlayerGUI() = default;
	int provideField(const Board& board) const override;
};