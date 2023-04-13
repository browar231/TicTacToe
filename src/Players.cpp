#include "Players.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
// Player
std::string Player::getName()
{
	return m_name;
}
// PlayerHuman
int PlayerHuman::provideField(Board& board)
{
	return askForInput();
}
int PlayerHuman::askForInput()
{
	int field;
	std::cout << "Field #";
	std::cin >> field;
	return field;
}
// PlayerCPU
int PlayerCPU::provideField(Board& board)
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1000ms);
	return returnRandomField(board);
	return 0;
}
int PlayerCPU::returnFirstAllowedField(Board& board)
{
	for (int i = 0; i < 9; i++) {
		if (board.isMoveAllowed(i)) {
			return i;
		}
	};
	return 0;
}
int PlayerCPU::returnRandomField(Board& board)
{
	std::vector<int> allowedFields;
	for (int i = 0; i < 9; i++) {
		if (board.isMoveAllowed(i)) {
			allowedFields.push_back(i);
		}
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, allowedFields.size());
	return allowedFields[distr(gen)];
}