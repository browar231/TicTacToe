#include "PlayerConsole.h"
#include "Console.h"
int PlayerConsole::provideField(const Board& board) const
{
	return askForInput();
}
int PlayerConsole::askForInput() const
{
	int field;
	Console::getInputUntilSuccess(field);
	return field;
}