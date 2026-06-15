#ifndef PLAYER_H
#define PLAYER_H

#include "Symbol.h"

class Player
{
public:
    Player(const Symbol& symbol);

    const char& getPlayer() const;

private:
    char m_player{};
};

#endif
