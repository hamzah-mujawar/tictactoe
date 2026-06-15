#include "Board.h"
#include "Player.h"
#include <iostream>
#include <vector>

int main()
{
    Board board{};
    Symbol symbol{'X'};
    board.setSymbol(0, 0, symbol);
    board.setSymbol(1, 1, symbol);
    board.setSymbol(2, 2, symbol);
    board.displayBoard();
    std::vector<std::vector<int>> test = board.moves();
    for (int i{0}; i < test.size(); ++i)
    {
        for (int j{0}; j < test[0].size(); ++j)
        {
            std::cout << test[i][j] << ' ';
        }
    }
}
