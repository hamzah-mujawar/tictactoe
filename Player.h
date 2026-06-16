#ifndef PLAYER_H
#define PLAYER_H

#include "Symbol.h"

class Player
{
public:
    Player(const Symbol& symbol);

    const Symbol& getPlayer() const;

private:
    Symbol m_player;
};

#endif
