#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
public:
    void displayBoard();

private:
    // rows and columns are equal
    const std::size_t m_boardSize{3};

    std::vector<std::vector<char>> m_board{m_boardSize,
                                           std::vector<char>(m_boardSize)};
};

#endif
