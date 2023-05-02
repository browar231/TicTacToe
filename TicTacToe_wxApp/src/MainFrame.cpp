#include "MainFrame.h"
#include "Board.h"
#include "TicTacToe_wxApp.h"

struct FieldId final : public wxClientData {
	int field;
};

MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250))
{
	wxButton* quitButton = new wxButton(this, wxID_EXIT, wxT("Quit"));
	wxButton* restartButton = new wxButton(this, ID_RESTART_BUTTON, wxT("Restart"));
	m_outputField = new wxStaticText(this, 0, wxT(""));
	auto sizer = new wxBoxSizer(wxVERTICAL);
	auto sizerButtons = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer* gs = new wxGridSizer(3, 3, 0, 0);
	for (int i = 0; i < 9; i++) {
		m_controls[i] = new wxButton(this, ID_CONTROL, wxString::Format(wxT("%i"), 0));
		gs->Add(m_controls[i]);
		FieldId* const data { new FieldId() };
		data->field = i;
		m_controls[i]->SetClientObject(data);
	}
	sizer->Add(m_outputField);
	sizer->Add(gs, 1, wxEXPAND);
	sizerButtons->Add(restartButton);
	sizerButtons->Add(quitButton);
	sizer->Add(sizerButtons);
	SetSizer(sizer);
	// events
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnQuit));
	Connect(ID_CONTROL, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnClick));
	Connect(ID_RESTART_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnRestart));
	// init
	Centre();
	m_game = new TicTacToe_wxApp(m_controls, m_lastField, m_outputField);
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

void MainFrame::OnRestart(wxCommandEvent& event)
{
	m_game->terminate();
	delete m_game;
	m_lastField = -1;
	m_outputField->SetLabel("");
	m_game = new TicTacToe_wxApp(m_controls, m_lastField, m_outputField);
	m_game->printBoard();
}

MainTimer::MainTimer(TicTacToe_wxApp* game)
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
