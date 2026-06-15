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
    bool isCellEmpty(std::size_t row, std::size_t column);
    void setSymbol(std::size_t row, std::size_t column, Symbol& symbol);

private:
    // rows and columns are equal
    const std::size_t m_boardSize{3};

    std::vector<std::vector<char>> m_board{m_boardSize,
                                           std::vector<char>(m_boardSize, 0)};
};

#endif
