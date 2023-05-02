#pragma once
#include "Board.h"
#include "Player.h"
#include <string>
class Player_ConsoleApp : public Player {
public:
	Player_ConsoleApp(const std::string& name, char sign)
		: Player(name, sign) {};
	virtual ~Player_ConsoleApp() = default;
	int provideField(const Board& board) const override;

private:
	int askForInput() const;
};