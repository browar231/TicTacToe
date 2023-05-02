#include "TicTacToe_wxApp.h"
#include "PlayerCPU.h"
#include "Player_wxApp.h"
TicTacToe_wxApp::TicTacToe_wxApp(std::array<wxButton*, 9> buttons, int& lastField, wxStaticText* outputBox)
	: m_buttons { buttons }
	, m_outputBox(outputBox)
{

	m_players.push_back(std::make_unique<PlayerCPU>("CPU 1", 'X', PlayerCPU_strategy::BeastMode));
	m_players.push_back(std::make_unique<Player_wxApp>("Player", 'O', lastField));
}

void TicTacToe_wxApp::printBoard() const
{
	for (int i = 0; i < 9; i++) {
		std::string label(1, m_board.getBoardArray()[i]);
		wxString wxLabel(label);
		// m_buttons[i]->SetLabel(wxT((m_board.getBoardArray()[i] - '0'));
		m_buttons[i]->SetLabel(wxLabel);
	}
}

void TicTacToe_wxApp::onWin(Player* winner) const
{
	std::string winnerPrompt = winner->getName() + " won!";
	m_outputBox->SetLabel(winnerPrompt);
}

void TicTacToe_wxApp::onDraw() const
{
	m_outputBox->SetLabel("Draw!");
}

void TicTacToe_wxApp::onBeforeStep(Player* currentPlayer) const
{
	m_outputBox->SetLabel(currentPlayer->getName() + " " + currentPlayer->getSign());
}
