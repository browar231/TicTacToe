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
	std::cout << "Player: " << m_players[m_currentPlayer]->getName() << '\n';
	int selectedField;
	while (true) {
		selectedField = m_players[m_currentPlayer]->provideField(m_board);
		if (m_board.isMoveAllowed(selectedField)) {
			break;
		} else {
			std::cout << "Invalid move\n";
		}
	}
	m_board.takeFieldOnBoard(selectedField, returnPlayerSign(m_currentPlayer));
	clearConsole();
	printBoard();
	if (m_board.isGameWon()) {
		std::cout
			<< m_players[m_currentPlayer]->getName() << "(" << returnPlayerSign(m_currentPlayer) << ") won!\n";
		terminate();
		return;
	}
	if (!m_board.areThereFreeFields()) {
		std::cout << "Game ended\n";
		terminate();
		return;
	}
	nextPlayer();
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
void TicTacToe::nextPlayer()
{
	m_currentPlayer += 1;
	m_currentPlayer %= 2;
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