#include "TicTacToe.h"
#include <memory>
#include <random>
#include <string>
#include <vector>
void TicTacToe::step()
{
	const auto& currentPlayer = m_players[currentPlayerId()].get();
	onBeforeStep(currentPlayer);
	onInput();
	int selectedField = currentPlayer->provideField(m_board);
	if (!m_board.isMoveAllowed(selectedField)) {
		onInvalidMove();
		return;
	}
	m_board.takeFieldOnBoard(selectedField, currentPlayer->getSign());
	printBoard();
	if (m_board.isGameWon()) {
		onWin(currentPlayer);
		terminate();
		return;
	}
	if (!m_board.areThereFreeFields()) {
		onDraw();
		terminate();
		return;
	}
}

int TicTacToe::currentPlayerId() const
{
	return (m_board.returnAllowedIds().size() + m_invertPlayers) % 2;
}
bool TicTacToe::isRunning() const
{
	return m_running;
}
void TicTacToe::terminate()
{
	m_running = false;
}
// randomness in first move
int TicTacToe::randomZeroOrOne() const
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, 1);
	return distr(gen);
}