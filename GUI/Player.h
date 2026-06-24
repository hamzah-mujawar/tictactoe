#ifndef PLAYER_H
#define PLAYER_H

#include "Symbol.h"

class Player
{
public:
    Player(const Symbol& symbol);
    const Symbol& getPlayer() const;
    void setPlayer(const char& player);

private:
    Symbol m_player;
};

#endif
