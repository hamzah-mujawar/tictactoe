#include "Board.h"
#include <ios>
#include <iostream>

int main()
{
    Board board{};
    board.displayBoard();
    std::cout << std::boolalpha << board.isCellEmpty(0, 0);
}
