#include "Board.h"
#include "Symbol.h"

#include <iostream>
#include <vector>

void Board::displayBoard() const
{
    std::cout << '\n';
    for (int i{0}; i < 3; ++i)
    {
        if (i != 0)
            std::cout << "\n  ----------------------------------------------\n";
        for (int j{0}; j < 3; ++j)
        {
            std::cout << "\t" << m_board[i][j];
            if (j != 2)
                std::cout << "\t|";
        }
    }
    std::cout << '\n';
}

bool Board::isCellFull(std::size_t row, std::size_t column)
{
    return (m_board[row][column] != 0);
}

void Board::setSymbol(std::size_t row, std::size_t column, const Symbol& symbol)
{
    m_board[row][column] = symbol.getSymbol();
}

bool Board::hasSpace()
{
    // hard coded player X and player O values here
    char playerX{'X'};
    char playerO{'O'};

    int count{0};

    // we check the rows and columns for any X and Os if they
    // amount to 9 that means the board is full and we return false
    for (std::size_t i{0}; i < m_board.size(); ++i)
    {
        for (std::size_t j{0}; j < m_board[0].size(); ++j)
        {
            if (m_board[i][j] == playerX || m_board[i][j] == playerO)
            {
                ++count; // incrementing count for any X or O's found
            }
        }
    }
    if (count == 9)
    {
        return false;
    }
    return true;
}

// This function returns a 2d vector of all the moves the players have done
std::vector<std::vector<int>> Board::occupiedCells()
{
    std::vector<std::vector<int>> boardState{};
    for (std::size_t i{0}; i < m_board.size(); ++i)
        for (std::size_t j{0}; j < m_board[0].size(); ++j)
        {
            if (isCellFull(i, j))
                boardState.push_back(
                    {static_cast<int>(i), static_cast<int>(j)});
        }
    return boardState;
}

bool Board::checkRows(char symbol) const
{
    for (int i = 0; i < m_board.size(); ++i)
    {
        if (m_board[i][0] == symbol && m_board[i][1] == symbol &&
            m_board[i][2] == symbol)
            return true;
    }
    return false;
}

bool Board::checkCols(char symbol) const
{
    for (int i = 0; i < m_board.size(); ++i)
    {
        if (m_board[0][i] == symbol && m_board[1][i] == symbol &&
            m_board[2][i] == symbol)
            return true;
    }
    return false;
}

bool Board::checkDiags(char symbol) const
{
    if (m_board[0][0] == symbol && m_board[1][1] == symbol &&
        m_board[2][2] == symbol)
        return true;
    else if (m_board[2][0] == symbol && m_board[1][1] == symbol &&
             m_board[0][2] == symbol)
        return true;
    return false;
}

bool Board::checkWin(char symbol) const
{
    return (checkRows(symbol) || checkCols(symbol) || checkDiags(symbol));
}
