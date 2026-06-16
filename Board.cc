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

void Board::setSymbol(std::size_t row, std::size_t column, const Symbol& symbol)
{
    m_board[row][column] = symbol.getSymbol();
}

bool Board::isFull()
{
    bool is_empty{false};
    for (std::size_t i{0}; i < m_board.size(); ++i)
    {
        for (std::size_t j{0}; j < m_board.size(); ++j)
        {
            if (isCellEmpty(i, j))
                is_empty = true;
            else
                is_empty = false;
        }
    }
    return is_empty;
}

std::vector<std::vector<int>> Board::occupiedCells()
{
    std::vector<std::vector<int>> boardState{};
    for (std::size_t i{0}; i < m_board.size(); ++i)
        for (std::size_t j{0}; j < m_board[0].size(); ++j)
        {
            if (!isCellEmpty(i, j))
                boardState.push_back(
                    {static_cast<int>(i), static_cast<int>(j)});
        }
    return boardState;
}
