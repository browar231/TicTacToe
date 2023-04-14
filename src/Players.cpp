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
	return board.returnAllowedIds()[0];
}
int PlayerCPU::returnRandomField(const Board& board)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, board.returnAllowedIds().size() - 1);
	return board.returnAllowedIds()[distr(gen)];
}