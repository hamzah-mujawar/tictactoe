#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game
{
public:
private:
    Board board{};
    Player player1{Symbol{'X'}};
    Player player2{Symbol{'O'}};
};

#endif
