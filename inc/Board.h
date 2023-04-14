#pragma once
#include <array>
#include <vector>
class Board {
public:
	Board();
	bool isGameWon() const;
	bool isMoveAllowed(const int field) const;
	bool areThereFreeFields() const;
	const std::vector<int>& returnAllowedIds() const;
	void takeFieldOnBoard(const int field, const char sign);
	void printBoard() const;

private:
	std::array<char, 9> m_board;
	std::vector<int> m_allowedFieldsIds;
	bool checkCol(const int) const;
	bool checkRow(const int) const;
	bool checkAllCols() const;
	bool checkAllRows() const;
	bool checkDiagonals() const;
};