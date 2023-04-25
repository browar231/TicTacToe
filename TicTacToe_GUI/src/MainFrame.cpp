#include "MainFrame.h"
#include "Board.h"
MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250))
{
	wxButton* quitButton = new wxButton(this, wxID_EXIT, wxT("Quit"));
	auto sizer = new wxBoxSizer(wxVERTICAL);
	wxGridSizer* gs = new wxGridSizer(3, 3, 0, 0);
	for (int i = 0; i < 9; i++) {
		m_buttons[i] = new wxButton(this, 0, wxString::Format(wxT("%i"), 0));
		gs->Add(m_buttons[i]);
	}
	sizer->Add(gs, 1, wxEXPAND);
	sizer->Add(quitButton, 0.5, wxEXPAND);
	SetSizer(sizer);
	// events
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnQuit));
	// init
	Centre();
	m_game = new TicTacToe_GUI(m_buttons);
	m_game->printBoard();
}
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close(true);
}