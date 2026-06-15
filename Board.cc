#include "Board.h"
#include "Symbol.h"

#include <iostream>
#include <vector>

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

std::vector<std::vector<int>> Board::moves()
{
    std::vector<std::vector<int>> boardState;
    for (int i{0}; i < m_board.size(); ++i)
        for (int j{0}; j < m_board[0].size(); ++j)
        {
            if (m_board[i][j] == 'X' || m_board[i][j] == 'O')
                boardState.push_back({i, j});
        }
    return boardState;
}
