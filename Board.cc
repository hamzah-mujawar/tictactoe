#include "Board.h"

#include <iostream>

void Board::displayBoard()
{
    for (const auto& row : m_board)
    {
        for (const auto& elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
}
