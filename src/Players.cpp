#include "Players.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <thread>
#include <vector>
// Player
std::string Player::getName()
{
	return m_name;
}
// PlayerHuman
int PlayerHuman::provideField(const Board& board)
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
int PlayerCPU::provideField(const Board& board)
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1000ms);
	return returnRandomField(board);
	return 0;
}
int PlayerCPU::returnFirstAllowedField(const Board& board)
{
	auto it = std::find(board.getAllowedArray().begin(), board.getAllowedArray().end(), true);
	if (it != board.getAllowedArray().end()) {
		return std::distance(board.getAllowedArray().begin(), it);
	}
	return 0;
}
int PlayerCPU::returnRandomField(const Board& board)
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