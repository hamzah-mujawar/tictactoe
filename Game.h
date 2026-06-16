#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Symbol.h"

class Game
{
public:
    void switchCurrPlayer(const Player* currPlayer);
    void makeTurn(std::size_t x, std::size_t y);
    void run();

private:
    Board m_board{};
    Player m_player1{Symbol{'X'}};
    Player m_player2{Symbol{'O'}};
    Player* m_currentPlayer{&m_player1};
};

#endif
