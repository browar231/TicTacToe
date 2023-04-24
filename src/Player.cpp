#include "Player.h"
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