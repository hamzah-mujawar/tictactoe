#include "Player.h"

Player::Player(const Symbol& symbol) : m_player{symbol.getSymbol()} {}

const char& Player::getPlayer() const { return m_player; }
