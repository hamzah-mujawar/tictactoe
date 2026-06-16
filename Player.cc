#include "Player.h"

Player::Player(const Symbol& symbol) : m_player{symbol} {}

const Symbol& Player::getPlayer() const { return m_player; }
