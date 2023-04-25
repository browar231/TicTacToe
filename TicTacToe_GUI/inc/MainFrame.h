#pragma once
#include "TicTacToe_GUI.h"
#include <array>
#include <wx/wx.h>
class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	std::array<wxButton*, 9> m_buttons;
	// TicTacToe
	TicTacToe_GUI* m_game;
};