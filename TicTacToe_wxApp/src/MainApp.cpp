#include "MainApp.h"
#include "MainFrame.h"
IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
	frame = new MainFrame(wxT("TicTacToe"));
	frame->Show(true);
	return true;
}