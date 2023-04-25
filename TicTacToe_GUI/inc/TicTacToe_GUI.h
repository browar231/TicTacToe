#pragma once
#include "TicTacToe.h"
#include <wx/wx.h>
class TicTacToe_GUI : public TicTacToe {
public:
	TicTacToe_GUI(std::array<wxButton*, 9> buttons);
	void printBoard() const override;
	std::array<wxButton*, 9> m_buttons;
};