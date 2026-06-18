#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Symbol.h"

#include <utility>

class Game
{
public:
    void switchCurrPlayer(const Player* currPlayer);
    void makeTurn(std::size_t x, std::size_t y);
    void playerWithComputer();
    void playerWithHuman();

    // minmax algorithm functions
    // Adapted from https://www.geeksforgeeks.org/dsa/finding-optimal-move-in-tic-tac-toe-using-minimax-algorithm-in-game-theory/
    int evaluate();
    int minimax(int depth, bool isMax);
    std::pair<int, int> findBestMove();
    void opponentMove();

private:
    Board m_board{};
    Player m_player1{Symbol{'X'}};
    Player m_player2{Symbol{'O'}};
    Player* m_currentPlayer{&m_player1};
};

std::size_t getUserRow();
std::size_t getUserCol();

#endif
