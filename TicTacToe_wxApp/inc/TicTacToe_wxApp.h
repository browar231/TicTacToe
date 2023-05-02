#pragma once
#include "TicTacToe.h"
#include <wx/wx.h>
class TicTacToe_wxApp : public TicTacToe {
public:
	TicTacToe_wxApp(std::array<wxButton*, 9> buttons, int& lastField, wxStaticText* outputBox);
	void printBoard() const override;
	void onWin(Player* winner) const override;
	void onDraw() const override;
	void onBeforeStep(Player* currentPlayer) const override;

private:
	std::array<wxButton*, 9> m_buttons;
	wxStaticText* m_outputBox;
};