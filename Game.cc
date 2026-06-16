#include "Game.h"
#include <iostream>

// This function is used to switch the currentPlayer
// to either player1 or player2
void Game::switchCurrPlayer(const Player* currPlayer)
{
    m_currentPlayer = ((currPlayer == &m_player1) ? &m_player2 : &m_player1);
}

// Function used to handle a turn on the board
void Game::makeTurn(std::size_t x, std::size_t y)
{
    if (m_board.isCellEmpty(x, y))
    {
        m_board.setSymbol(x, y, m_currentPlayer->getPlayer());
        switchCurrPlayer(m_currentPlayer); // switch player after move
    }
}

std::size_t getUserRow()
{
    std::size_t row{};

    std::cout << "Row No: ";
    std::cin >> row;
    while (row > 2 || row < 0)
    {
        std::cout << "Please enter a value between 0 and 2" << '\n';
        std::cin >> row;
    }
    return row;
}

std::size_t getUserCols()
{
    std::size_t col{};

    std::cout << "Column No: ";
    std::cin >> col;
    while (col > 2 || col < 0)
    {
        std::cout << "Please enter a value between 0 and 2" << '\n';
        std::cin >> col;
    }

    return col;
}

void Game::run()
{
    while (m_board.isFull())
    {
        std::size_t x{getUserRow()};
        std::size_t y{getUserCols()};

        makeTurn(x, y);
        m_board.displayBoard();
    }
    std::cout << "Draw!" << '\n';
}
