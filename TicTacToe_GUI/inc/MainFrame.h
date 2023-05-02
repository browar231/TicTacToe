#pragma once
#include "TicTacToe_GUI.h"
#include <array>
#include <wx/wx.h>
enum {
	ID_CONTROL = 999,
	ID_RESTART_BUTTON
};
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
	void OnRestart(wxCommandEvent& event);
	std::array<wxButton*, 9> m_controls;
	wxStaticText* m_outputField;
	// TicTacToe
	int m_lastField { -1 };
	TicTacToe_GUI* m_game;
};