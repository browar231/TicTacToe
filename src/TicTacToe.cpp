#include "TicTacToe.h"
#include "Console.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
TicTacToe::TicTacToe(const int numberOfHumanPlayers)
{
	switch (numberOfHumanPlayers) {
	case 0:
		m_players.push_back(std::make_unique<PlayerCPU>("CPU 1", 'X'));
		m_players.push_back(std::make_unique<PlayerCPU>("CPU 2", 'O'));
		break;
	case 1:
		m_players.push_back(std::make_unique<PlayerHuman>("Player", 'X'));
		m_players.push_back(std::make_unique<PlayerCPU>("CPU", 'O'));
		break;
	case 2:
	default:
		m_players.push_back(std::make_unique<PlayerHuman>("Player 1", 'X'));
		m_players.push_back(std::make_unique<PlayerHuman>("Player 2", 'O'));
	}
}
void TicTacToe::step()
{
	const auto& currentPlayer = m_players[currentPlayerId()].get();
	std::cout << "Player: " << currentPlayer->getName() << '\n';
	int selectedField;
	while (true) {
		selectedField = currentPlayer->provideField(m_board);
		if (m_board.isMoveAllowed(selectedField)) {
			break;
		} else {
			std::cout << "Invalid move\n";
		}
	}
	m_board.takeFieldOnBoard(selectedField, currentPlayer->getSign());
	Console::clear();
	printBoard();
	if (m_board.isGameWon()) {
		std::cout
			<< currentPlayer->getName() << "(" << currentPlayer->getSign() << ") won!\n";
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
int TicTacToe::currentPlayerId() const
{
	return m_board.returnAllowedIds().size() % 2;
}
void TicTacToe::intro()
{
	std::cout << "Tic Tac Toe game\n"
			  << "To make a move, enter number of field\n";
}
bool TicTacToe::isRunning() const
{
	return m_running;
}
void TicTacToe::terminate()
{
	m_running = false;
}