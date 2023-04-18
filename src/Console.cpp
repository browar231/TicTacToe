#include "Console.h"
#include <iostream>
#include <string>
void Console::clear()
{
	std::cout << "\033[2J";
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
