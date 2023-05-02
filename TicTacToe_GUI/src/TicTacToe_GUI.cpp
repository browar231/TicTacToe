#include "TicTacToe_GUI.h"
#include "PlayerCPU.h"
#include "PlayerGUI.h"
TicTacToe_GUI::TicTacToe_GUI(std::array<wxButton*, 9> buttons, int& lastField, wxStaticText* outputBox)
	: m_buttons { buttons }
	, m_outputBox(outputBox)
{

	m_players.push_back(std::make_unique<PlayerCPU>("CPU 1", 'X', PlayerCPU_strategy::BeastMode));
	m_players.push_back(std::make_unique<PlayerGUI>("Player", 'O', lastField));
}

void TicTacToe_GUI::printBoard() const
{
	for (int i = 0; i < 9; i++) {
		std::string label(1, m_board.getBoardArray()[i]);
		wxString wxLabel(label);
		// m_buttons[i]->SetLabel(wxT((m_board.getBoardArray()[i] - '0'));
		m_buttons[i]->SetLabel(wxLabel);
	}
}

void TicTacToe_GUI::onWin(Player* winner) const
{
	std::string winnerPrompt = winner->getName() + " won!";
	m_outputBox->SetLabel(winnerPrompt);
}

void TicTacToe_GUI::onDraw() const
{
	m_outputBox->SetLabel("Draw!");
}

void TicTacToe_GUI::onBeforeStep(Player* currentPlayer) const
{
	m_outputBox->SetLabel(currentPlayer->getName() + " " + currentPlayer->getSign());
}
