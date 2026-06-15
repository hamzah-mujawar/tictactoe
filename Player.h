#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    // constructing a Player with a symbol either X or O
    Player(char symbol);

private:
    char m_player{};
};

#endif
