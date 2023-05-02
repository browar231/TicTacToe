#include "Player_ConsoleApp.h"
#include "Console.h"
int Player_ConsoleApp::provideField(const Board& board) const
{
	return askForInput();
}
int Player_ConsoleApp::askForInput() const
{
	int field;
	Console::getInputUntilSuccess(field);
	return field;
}