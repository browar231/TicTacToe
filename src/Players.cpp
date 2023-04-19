#include "Players.h"
#include "Console.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <iterator>
#include <random>
#include <thread>
#include <vector>
// Player
const std::string& Player::getName() const
{
	return m_name;
}
char Player::getSign() const
{
	return m_sign;
}
char Player::returnOpponentSign() const
{
	if (m_sign == 'O') {
		return 'X';
	}
	return 'O';
}
// PlayerHuman
int PlayerHuman::provideField(const Board& board) const
{
	return askForInput();
}
int PlayerHuman::askForInput() const
{
	int field;
	Console::getInputUntilSuccess(field);
	return field;
}
// PlayerCPU
int PlayerCPU::provideField(const Board& board) const
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1000ms);
	switch (m_strategy) {
	case PlayerCPU_strategy::FirstAllowed:
		return returnFirstAllowedField(board);
	case PlayerCPU_strategy::Random:
		return returnRandomField(board);
	case PlayerCPU_strategy::WinIfPossible:
		return returnWinningOrRandom(board);
	case PlayerCPU_strategy::WinOrBlock:
		return returnWinningOrBlocking(board);
	case PlayerCPU_strategy::BeastMode:
		return returnBestMove(board);
	}
	return 0;
}
int PlayerCPU::returnFirstAllowedField(const Board& board) const
{
	return board.returnAllowedIds()[0];
}
int PlayerCPU::returnRandomField(const Board& board) const
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, board.returnAllowedIds().size() - 1);
	return board.returnAllowedIds()[distr(gen)];
}

int PlayerCPU::returnWinningOrRandom(const Board& board) const
{
	int field = returnRandomField(board);
	for (const int& moveCandidate : board.returnAllowedIds()) {
		Board sandboxBoard = board;
		sandboxBoard.takeFieldOnBoard(moveCandidate, m_sign);
		if (sandboxBoard.isGameWon()) {
			return moveCandidate;
		}
	}
	return field;
}

int PlayerCPU::returnWinningOrBlocking(const Board& board) const
{
	int field = returnWinningOrRandom(board);
	for (const int& moveCandidate : board.returnAllowedIds()) {
		Board sandboxBoard = board;
		sandboxBoard.takeFieldOnBoard(moveCandidate, returnOpponentSign());
		if (sandboxBoard.isGameWon()) {
			return moveCandidate;
		}
	}
	return field;
}

int PlayerCPU::returnBestMove(const Board& board) const
{
	// entry point - first valid option
	int field = returnFirstAllowedField(board);
	// avoid edges if possible (in this implementation they have odd identifiers so find first even id)
	for (const int& moveCandidate : board.returnAllowedIds()) {
		if (!(moveCandidate % 2)) {
			field = moveCandidate;
			break;
		}
	}
	// if opponent didn't choose center, cpu does it
	if (board.isMoveAllowed(4)) {
		field = 4;
	}
	// but if you can detect winning move - do it!...
	for (const int& moveCandidate : board.returnAllowedIds()) {
		Board sandboxBoard = board;
		sandboxBoard.takeFieldOnBoard(moveCandidate, m_sign);
		if (sandboxBoard.isGameWon()) {
			return moveCandidate;
		}
	}
	//... or at least block opponent
	for (const int& moveCandidate : board.returnAllowedIds()) {
		Board sandboxBoard = board;
		sandboxBoard.takeFieldOnBoard(moveCandidate, returnOpponentSign());
		if (sandboxBoard.isGameWon()) {
			return moveCandidate;
		}
	}
	return field;
}
