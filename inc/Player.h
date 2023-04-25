#pragma once
#include "Board.h"
#include <string>

class Player {
public:
	Player(const std::string& name, char sign)
		: m_name(name)
		, m_sign(sign) {};
	virtual ~Player() = default;
	virtual int provideField(const Board& board) const = 0;
	const std::string& getName() const;
	char getSign() const;

protected:
	char returnOpponentSign() const;
	const char m_sign;
	const std::string m_name;
};