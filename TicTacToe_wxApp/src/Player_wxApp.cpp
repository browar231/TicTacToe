#include "Player_wxApp.h"
// rancommove
#include "PlayerCPU.h"
#include <memory>

int Player_wxApp::provideField(const Board& board) const
{
	return *p_lastField;
}