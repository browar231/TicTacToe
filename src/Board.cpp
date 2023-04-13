#include "Board.h"
#include <iostream>
Board::Board()
{
	for (int i = 0; i < 9; i++) {
		m_board[i] = i + '0';
		m_allowed[i] = true;
	};
}
std::array<bool, 9> Board::getAllowedArray()
{
	return m_allowed;
}
void Board::takeFieldOnBoard(const int field, const char sign)
{
	m_allowed[field] = false;
	m_board[field] = sign;
}
bool Board::isMoveAllowed(const int field)
{
	if (field >= 0 && field < 9) {
		return m_allowed[field];
	}
	return false;
}
bool Board::areThereFreeFields()
{
	for (int i = 0; i < 9; i++) {
		if (m_allowed[i])
			return true;
	}
	return false;
}
bool Board::isGameWon()
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
bool Board::checkRow(const int row)
{
	if (m_board[row] == m_board[row + 1] && m_board[row + 1] == m_board[row + 2]) {
		return true;
	}
	return false;
}
bool Board::checkAllRows()
{
	for (int i = 0; i < 9; i += 3) {
		if (checkRow(i)) {
			return true;
		}
	}
	return false;
}
bool Board::checkCol(const int col)
{
	if (m_board[col] == m_board[col + 3] && m_board[col + 3] == m_board[col + 6]) {
		return true;
	}
	return false;
}
bool Board::checkAllCols()
{
	for (int i = 0; i < 3; i++) {
		if (checkCol(i)) {
			return true;
		}
	}
	return false;
}
bool Board::checkDiagonals()
{
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8]) {
		return true;
	}
	if (m_board[2] == m_board[4] && m_board[4] == m_board[6]) {
		return true;
	}
	return false;
}
void Board::printBoard()
{
	for (int i = 0; i < 9; i += 3) {
		std::cout << m_board[i] << '|' << m_board[i + 1] << '|' << m_board[i + 2] << std::endl;
		if (i < 6) {
			std::cout << "_____" << std::endl;
		}
	}
}