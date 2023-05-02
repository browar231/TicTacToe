#include "MainFrame.h"
#include "Board.h"
#include "TicTacToe_GUI.h"

struct FieldId final : public wxClientData {
	int field;
};

MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250))
{
	wxButton* quitButton = new wxButton(this, wxID_EXIT, wxT("Quit"));
	auto sizer = new wxBoxSizer(wxVERTICAL);
	wxGridSizer* gs = new wxGridSizer(3, 3, 0, 0);
	for (int i = 0; i < 9; i++) {
		m_controls[i] = new wxButton(this, 0, wxString::Format(wxT("%i"), 0));
		gs->Add(m_controls[i]);
		FieldId* const data { new FieldId() };
		data->field = i;
		m_controls[i]->SetClientObject(data);
	}
	sizer->Add(gs, 1, wxEXPAND);
	sizer->Add(quitButton, 0.5, wxEXPAND);
	SetSizer(sizer);
	m_outputField = new wxStaticText(this, 0, wxT(""));
	// events
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnQuit));
	Connect(0, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnClick));
	// init
	Centre();
	m_game = new TicTacToe_GUI(m_controls, m_lastField, m_outputField);
	m_game->printBoard();

	auto* timer = new MainTimer(m_game);
	timer->start();
}
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close(true);
}

void MainFrame::OnClick(wxCommandEvent& event)
{
	wxButton* lastButton = wxDynamicCast(event.GetEventObject(), wxButton);

	FieldId const* const myData { static_cast<FieldId const*>(lastButton->GetClientObject()) };
	m_lastField = myData->field;
}

MainTimer::MainTimer(TicTacToe_GUI* game)
	: wxTimer()
	, m_game(game)
{
}
void MainTimer::Notify()
{
	if (m_game->isRunning()) {
		m_game->step();
	}
}
void MainTimer::start()
{
	wxTimer::Start(500);
}
