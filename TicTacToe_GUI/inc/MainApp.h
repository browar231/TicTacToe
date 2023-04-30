#pragma once
#include "MainFrame.h"
#include <wx/wx.h>

class MainApp : public wxApp {
public:
	virtual bool OnInit();
	MainFrame* frame;
};