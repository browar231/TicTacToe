#include "Board.h"
#include <algorithm>
#include <iostream>

Board::Board()
{
	m_allowedFieldsIds.reserve(9);
	for (int i = 0; i < 9; i++) {
		m_board[i] = i + '0';
		m_allowedFieldsIds.push_back(i);
	};
}
const std::vector<int>& Board::returnAllowedIds() const
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
bool Board::areThereFreeFields() const
{
	return !m_allowedFieldsIds.empty();
}
bool Board::isGameWon() const
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
bool Board::checkRow(const int row) const
{
	if (m_board[row] == m_board[row + 1] && m_board[row + 1] == m_board[row + 2]) {
		return true;
	}
	return false;
}
bool Board::checkAllRows() const
{
	for (int i = 0; i < 9; i += 3) {
		if (checkRow(i)) {
			return true;
		}
	}
	return false;
}
bool Board::checkCol(const int col) const
{
	if (m_board[col] == m_board[col + 3] && m_board[col + 3] == m_board[col + 6]) {
		return true;
	}
	return false;
}
bool Board::checkAllCols() const
{
	for (int i = 0; i < 3; i++) {
		if (checkCol(i)) {
			return true;
		}
	}
	return false;
}
bool Board::checkDiagonals() const
{
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8]) {
		return true;
	}
	if (m_board[2] == m_board[4] && m_board[4] == m_board[6]) {
		return true;
	}
	return false;
}
void Board::printBoard() const
{
	for (int i = 0; i < 9; i += 3) {
		std::cout << m_board[i] << '|' << m_board[i + 1] << '|' << m_board[i + 2] << '\n';
		if (i < 6) {
			std::cout << "_____\n";
		}
	}
	std::cout << '\n';
}