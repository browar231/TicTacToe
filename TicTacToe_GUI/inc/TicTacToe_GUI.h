#pragma once
#include "TicTacToe.h"
#include <wx/wx.h>
class TicTacToe_GUI : public TicTacToe {
public:
	TicTacToe_GUI(std::array<wxButton*, 9> buttons, int& lastField, wxStaticText* outputBox);
	void printBoard() const override;
	void onWin(Player* winner) const override;
	void onDraw() const override;

private:
	std::array<wxButton*, 9> m_buttons;
	wxStaticText* m_outputBox;
};