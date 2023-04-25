#include "MainFrame.h"
MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250))
{
	wxButton* quitButton = new wxButton(this, wxID_EXIT, wxT("Quit"));

	SetMinSize(wxSize(400, 250));
	SetMaxSize(wxSize(400, 250));

	// events
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnQuit));
	// init
	Centre();
}
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close(true);
}