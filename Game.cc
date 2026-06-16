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

void Game::run()
{
    std::size_t x{};
    std::size_t y{};

    std::cin >> x >> y;

    makeTurn(x, y);
}
