#include "Players.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
std::string Player::getName()
{
	return m_name;
}
int PlayerHuman::move(const bool allowed[9])
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
int PlayerCPU::move(const bool allowed[9])
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1000ms);
	return moveRandom(allowed);
	return 0;
}
int PlayerCPU::moveFirstAllowed(const bool allowed[9])
{
	for (int i = 0; i < 9; i++) {
		if (allowed[i]) {
			return i;
		}
	};
	return 0;
}
int PlayerCPU::moveRandom(const bool allowed[9])
{
	std::vector<int> allowedFields;
	for (int i = 0; i < 9; i++) {
		if (allowed[i]) {
			allowedFields.push_back(i);
		}
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, allowedFields.size());
	return allowedFields[distr(gen)];
}
int PlayerHuman::s_id = 1;
int PlayerCPU::s_id = 1;