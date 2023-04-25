#include "TicTacToe_GUI.h"
#include "PlayerCPU.h"
TicTacToe_GUI::TicTacToe_GUI(std::array<wxButton*, 9> buttons)
	: m_buttons { buttons }
{

	m_players.push_back(std::make_unique<PlayerCPU>("CPU 1", 'X', PlayerCPU_strategy::BeastMode));
	m_players.push_back(std::make_unique<PlayerCPU>("CPU 2", 'O', PlayerCPU_strategy::BeastMode));
}

void TicTacToe_GUI::printBoard() const
{
	for (int i = 0; i < 9; i++) {
		m_buttons[i]->SetLabel(wxString::Format(wxT("%i"), m_board.getBoardArray()[i] - '0'));
	}
}
