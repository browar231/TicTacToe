#pragma once
#include "TicTacToe_GUI.h"
#include <array>
#include <wx/wx.h>
class MainTimer : public wxTimer {
	TicTacToe_GUI* m_game;

public:
	MainTimer(TicTacToe_GUI* game);
	void Notify();
	void start();
};
class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	void OnClick(wxCommandEvent& event);
	std::array<wxButton*, 9> m_buttons;
	wxStaticText* output;
	// TicTacToe
	int m_lastField { -1 };
	TicTacToe_GUI* m_game;
};