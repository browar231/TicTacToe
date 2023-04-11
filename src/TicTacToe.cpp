#include "TicTacToe.h"
#include <iostream>
#include <string>
TicTacToe::TicTacToe()
{
	m_players[0] = new PlayerHuman;
	m_players[1] = new PlayerCPU;
	initializeAllowed();
	initializeBoard();
}
TicTacToe::TicTacToe(Player* player1, Player* player2)
{
	m_players[0] = player1;
	m_players[1] = player2;
	initializeAllowed();
	initializeBoard();
}
void TicTacToe::step()
{
	if (isGameWon()) {
		m_currentPlayer += 1;
		m_currentPlayer %= 2;
		std::cout << m_players[m_currentPlayer]->getName() << " won!" << std::endl;
		terminate();
		return;
	}
	if (!areThereFreeFields()) {
		std::cout << "Game ended" << std::endl;
		terminate();
		return;
	}
	int selectedField = m_players[m_currentPlayer]->move(m_allowed);
	m_allowed[selectedField] = false;
	m_board[selectedField] = (m_currentPlayer % 2) ? 'x' : 'o';
	m_currentPlayer += 1;
	m_currentPlayer %= 2;
}
void TicTacToe::printBoard()
{
	for (int i = 0; i < 9; i += 3) {
		std::cout << m_board[i] << '|' << m_board[i + 1] << '|' << m_board[i + 2] << std::endl;
		if (i < 6) {
			std::cout << "_____" << std::endl;
		}
	}
}
void TicTacToe::intro()
{
	std::cout << "Tic Tac Toe game" << std::endl;
	std::cout << "To make a move, enter number of field" << std::endl;
}
std::string TicTacToe::getInputFromConsole()
{
	std::string input;
	std::cin >> input;
	return input;
}
bool TicTacToe::isRunning()
{
	return m_running;
}
void TicTacToe::terminate()
{
	m_running = false;
}
void TicTacToe::initializeAllowed()
{
	for (int i = 0; i < 9; i++) {
		m_allowed[i] = true;
	};
}
void TicTacToe::initializeBoard()
{
	for (int i = 0; i < 9; i++) {
		m_board[i] = i + '0';
	};
}
bool TicTacToe::isGameWon()
{
	if (checkAllCols()) {
		return true;
	}
	if (checkAllRows()) {
		return true;
	}
	if (checkDiagonals()) {
		return true;
	}
	return false;
}
bool TicTacToe::checkRow(int row)
{
	if (m_board[row] == m_board[row + 1] && m_board[row + 1] == m_board[row + 2]) {
		return true;
	}
	return false;
}
bool TicTacToe::checkAllRows()
{
	for (int i = 0; i < 3; i++) {
		if (checkRow(i)) {
			return true;
		}
	}
	return false;
}
bool TicTacToe::checkCol(int col)
{
	if (m_board[col] == m_board[col + 3] && m_board[col + 3] == m_board[col + 6]) {
		return true;
	}
	return false;
}
bool TicTacToe::checkAllCols()
{
	for (int i = 0; i < 3; i++) {
		if (checkCol(i)) {
			return true;
		}
	}
	return false;
}
bool TicTacToe::checkDiagonals()
{
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8]) {
		return true;
	}
	if (m_board[2] == m_board[4] && m_board[4] == m_board[6]) {
		return true;
	}
	return false;
}
bool TicTacToe::areThereFreeFields()
{
	for (int i = 0; i < 9; i++) {
		if (m_allowed[i])
			return true;
	}
	return false;
}