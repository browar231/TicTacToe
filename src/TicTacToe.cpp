#include "TicTacToe.h"
#include "Console.h"
// #include <iostream>
#include <memory>
#include <string>
#include <vector>
TicTacToe::TicTacToe(const int numberOfHumanPlayers)
{
	switch (numberOfHumanPlayers) {
	case 0:
		m_players.push_back(std::make_unique<PlayerCPU>("CPU 1", 'X', PlayerCPU_strategy::BeastMode));
		m_players.push_back(std::make_unique<PlayerCPU>("CPU 2", 'O', PlayerCPU_strategy::BeastMode));
		break;
	case 1:
		m_players.push_back(std::make_unique<PlayerCPU>("CPU", 'O', PlayerCPU_strategy::BeastMode));
		m_players.push_back(std::make_unique<PlayerHuman>("Player", 'X'));
		break;
	case 2:
	default:
		m_players.push_back(std::make_unique<PlayerHuman>("Player 1", 'X'));
		m_players.push_back(std::make_unique<PlayerHuman>("Player 2", 'O'));
	}
}
void TicTacToe::step()
{
	const auto& currentPlayer = m_players[currentPlayerId()].get();
	onBeforeStep();
	int selectedField;
	while (true) {
		onInput();
		selectedField = currentPlayer->provideField(m_board);
		if (m_board.isMoveAllowed(selectedField)) {
			break;
		} else {
			onInvalidMove();
		}
	}
	m_board.takeFieldOnBoard(selectedField, currentPlayer->getSign());
	Console::clear();
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
	return m_board.returnAllowedIds().size() % 2;
}
bool TicTacToe::isRunning() const
{
	return m_running;
}
void TicTacToe::terminate()
{
	m_running = false;
}