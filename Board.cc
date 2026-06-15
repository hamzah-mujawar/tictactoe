#include "Board.h"
#include "Symbol.h"

#include <iostream>

void Board::displayBoard() const
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

bool Board::isCellEmpty(std::size_t row, std::size_t column)
{
    return m_board[row][column] == 0;
}

void Board::setSymbol(std::size_t row, std::size_t column, Symbol& symbol)
{
    m_board[row][column] = symbol.getSymbol();
}
