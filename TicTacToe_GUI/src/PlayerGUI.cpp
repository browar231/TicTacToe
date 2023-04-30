#include "PlayerGUI.h"
// rancommove
#include "PlayerCPU.h"
#include <memory>

int PlayerGUI::provideField(const Board& board) const
{
	return *p_lastField;
}