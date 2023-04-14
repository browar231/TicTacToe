#pragma once
#include <array>
#include <vector>
class Board {
public:
	Board();
	bool isGameWon();
	bool isMoveAllowed(const int field) const;
	bool areThereFreeFields();
	std::vector<int> const& returnAllowedIds() const;
	void takeFieldOnBoard(const int field, const char sign);
	void printBoard();

private:
	std::array<char, 9> m_board;
	std::vector<int> m_allowedFieldsIds;
	bool checkCol(const int);
	bool checkRow(const int);
	bool checkAllCols();
	bool checkAllRows();
	bool checkDiagonals();
};