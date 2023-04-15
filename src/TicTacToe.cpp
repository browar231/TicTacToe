#include "TicTacToe.h"
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <string>
#include <vector>
TicTacToe::TicTacToe(const int numberOfHumanPlayers)
{
	switch (numberOfHumanPlayers) {
	case 0:
		m_players.push_back(std::make_unique<PlayerCPU>("CPU 1"));
		m_players.push_back(std::make_unique<PlayerCPU>("CPU 2"));
		break;
	case 1:
		m_players.push_back(std::make_unique<PlayerHuman>("Player"));
		m_players.push_back(std::make_unique<PlayerCPU>("CPU"));
		break;
	case 2:
	default:
		m_players.push_back(std::make_unique<PlayerHuman>("Player 1"));
		m_players.push_back(std::make_unique<PlayerHuman>("Player 2"));
	}
}
void TicTacToe::step()
{
	std::cout << "Player: " << m_players[currentPlayerId()]->getName() << '\n';
	int selectedField;
	while (true) {
		selectedField = m_players[currentPlayerId()]->provideField(m_board);
		if (m_board.isMoveAllowed(selectedField)) {
			break;
		} else {
			std::cout << "Invalid move\n";
		}
	}
	m_board.takeFieldOnBoard(selectedField, returnPlayerSign(currentPlayerId()));
	clearConsole();
	printBoard();
	if (m_board.isGameWon()) {
		// TODO: find a way to not use !
		std::cout
			<< m_players[!currentPlayerId()]->getName() << "(" << returnPlayerSign(!currentPlayerId()) << ") won!\n";
		terminate();
		return;
	}
	if (!m_board.areThereFreeFields()) {
		std::cout << "Game ended\n";
		terminate();
		return;
	}
}
void TicTacToe::printBoard() const
{
	m_board.printBoard();
}
char TicTacToe::returnPlayerSign(const int player) const
{
	if (player == 0) {
		return 'X';
	}
	return 'O';
}
int TicTacToe::currentPlayerId() const
{
	return m_board.returnAllowedIds().size() % 2;
}
void TicTacToe::clearConsole()
{
	system("clear");
}
void TicTacToe::intro()
{
	std::cout << "Tic Tac Toe game\n"
			  << "To make a move, enter number of field\n";
}
std::string TicTacToe::getInputFromConsole()
{
	std::string input;
	std::cin >> input;
	return input;
}
bool TicTacToe::isRunning() const
{
	return m_running;
}
void TicTacToe::terminate()
{
	m_running = false;
}