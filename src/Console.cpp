#include "Console.h"
#include <iostream>
#include <stdlib.h>
#include <string>
void Console::clear()
{
	system("clear");
}

bool Console::getInput(int& targetVariable)
{
std:
	std::string line;
	if (!std::getline(std::cin, line)) {
		return false;
	}
	try {
		targetVariable = stoi(line);
	} catch (...) {
		return false;
	}

	return true;
}

void Console::getInputUntilSuccess(int& targetVariable)
{
	while (true) {
		if (getInput(targetVariable)) {
			break;
		}
	}
}
