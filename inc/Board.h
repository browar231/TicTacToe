#pragma once
#include <array>
class Board {
public:
	Board();
	bool isGameWon();
	bool isMoveAllowed(const int field);
	bool areThereFreeFields();
	std::array<bool, 9> getAllowedArray();
	void takeFieldOnBoard(const int field, const char sign);
	void printBoard();

private:
	std::array<char, 9> m_board;
	std::array<bool, 9> m_allowed;
	bool checkCol(const int);
	bool checkRow(const int);
	bool checkAllCols();
	bool checkAllRows();
	bool checkDiagonals();
};