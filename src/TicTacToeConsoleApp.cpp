#include "TicTacToeConsoleApp.h"
#include <iostream>
void TicTacToeConsoleApp::onBeforeStep() const
{
	const auto& currentPlayer = m_players[currentPlayerId()].get();
	std::cout << "Player: " << currentPlayer->getName() << '\n';
}
void TicTacToeConsoleApp::onInvalidMove() const
{
	std::cout << "Invalid move\n";
}
void TicTacToeConsoleApp::onWin(Player* currentPlayer) const
{
	std::cout
		<< currentPlayer->getName() << "(" << currentPlayer->getSign() << ") won!\n";
}
void TicTacToeConsoleApp::onDraw() const
{
	std::cout << "Draw!\n";
}
void TicTacToeConsoleApp::onInput() const
{
	std::cout << "Field #";
}
void TicTacToeConsoleApp::printBoard() const
{
	std::cout << '\n';
	for (int i = 0; i < 9; i += 3) {
		std::cout << m_board.getBoardArray()[i] << '|' << m_board.getBoardArray()[i + 1] << '|' << m_board.getBoardArray()[i + 2] << '\n';
		if (i < 6) {
			std::cout << "_____\n";
		}
	}
	std::cout << '\n';
}
void TicTacToeConsoleApp::intro()
{
	std::cout << "Tic Tac Toe game\n"
			  << "To make a move, enter number of field\n";
}