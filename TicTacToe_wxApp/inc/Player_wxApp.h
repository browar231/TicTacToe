#pragma once
#include "Player.h"
#include <wx/wx.h>
class Player_wxApp : public Player {
public:
	Player_wxApp(const std::string& name, char sign, int& lastField)
		: Player(name, sign)
		, m_lastField(lastField)
		, p_lastField(&lastField) {};
	virtual ~Player_wxApp() = default;
	int provideField(const Board& board) const override;

private:
	int m_lastField;
	int* p_lastField;
};