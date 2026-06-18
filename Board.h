#ifndef BOARD_H
#define BOARD_H

#include <cstddef>
#include <vector>

#include "Symbol.h"

class Board
{
public:
    Board() = default;
    Board(const Board& board) = delete;
    Board(Board&& board) = delete;
    ~Board() = default;
    Board& operator=(const Board& board) = delete;
    Board& operator=(Board&& board) = delete;

    void displayBoard() const;
    bool isCellFull(std::size_t row, std::size_t column);
    void setSymbol(std::size_t row, std::size_t column, const Symbol& symbol);
    std::vector<std::vector<int>> occupiedCells();
    bool hasSpace();

    bool checkCols(char symbol) const;
    bool checkRows(char symbol) const;
    bool checkDiags(char symbol) const;
    bool checkWin(char symbol) const;

    char& operator()(std::size_t row, std::size_t col);

private:
    // rows and columns are equal
    const std::size_t m_boardSize{3};

    std::vector<std::vector<char>> m_board{m_boardSize,
                                           std::vector<char>(m_boardSize, 0)};
};

#endif
