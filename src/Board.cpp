#include "Board.h"
#include <algorithm>
#include <iostream>

Board::Board()
{
	for (int i = 0; i < 9; i++) {
		m_board[i] = i + '0';
		m_allowedFieldsIds.push_back(i);
	};
}
std::vector<int> const& Board::returnAllowedIds() const
{
	return m_allowedFieldsIds;
}
void Board::takeFieldOnBoard(const int field, const char sign)
{
	m_board[field] = sign;
	m_allowedFieldsIds.erase(std::remove(m_allowedFieldsIds.begin(), m_allowedFieldsIds.end(), field), m_allowedFieldsIds.end());
}
bool Board::isMoveAllowed(const int field) const
{
	auto it = std::find(m_allowedFieldsIds.begin(), m_allowedFieldsIds.end(), field);
	if (it != m_allowedFieldsIds.end()) {
		return true;
	}
	return false;
}
bool Board::areThereFreeFields()
{
	return !m_allowedFieldsIds.empty();
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