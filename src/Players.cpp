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
int PlayerHuman::provideField(const std::array<bool, 9>& allowed)
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
int PlayerCPU::provideField(const std::array<bool, 9>& allowed)
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1000ms);
	return returnRandomField(allowed);
	return 0;
}
int PlayerCPU::returnFirstAllowedField(const std::array<bool, 9>& allowed)
{
	for (int i = 0; i < 9; i++) {
		if (allowed[i]) {
			return i;
		}
	};
	return 0;
}
int PlayerCPU::returnRandomField(const std::array<bool, 9>& allowed)
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