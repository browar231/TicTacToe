#include "Players.h"
#include <chrono>
#include <iostream>
#include <thread>
std::string Player::getName()
{
	return m_name;
}
int PlayerHuman::move(const bool allowed[9])
{
	while (true) {
		int field = askForInput();
		if (field >= 0 && field <= 8 && allowed[field]) {
			return field;
		}
	}
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
	for (int i = 0; i < 9; i++) {
		if (allowed[i]) {
			return i;
		}
	};
	return 0;
}
int PlayerHuman::s_id = 1;
int PlayerCPU::s_id = 1;