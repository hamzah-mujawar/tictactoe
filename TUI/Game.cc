#include "Game.h"
#include <algorithm>
#include <iostream>
#include <utility>

// This function is used to switch the currentPlayer
// to either player1 or player2
void Game::switchCurrPlayer(const Player* currPlayer)
{
    m_currentPlayer = ((currPlayer == &m_player1) ? &m_player2 : &m_player1);
}

// Function used to handle a turn on the board
void Game::makeTurn(std::size_t x, std::size_t y)
{
    if (!m_board.isCellFull(x, y))
    {
        m_board.setSymbol(x, y, m_currentPlayer->getPlayer());
    }
    else
    {
        std::cout << "This cell is occupied, try again\n";
        // switch the current player back to this player
        // so they may input again
        switchCurrPlayer(m_currentPlayer);
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

int Game::evaluate()
{
    // this is player1 and player2's char value X and O
    char player1{m_player1.getPlayer().getSymbol()};
    char player2{m_player2.getPlayer().getSymbol()};

    for (int row{0}; row < 3; ++row)
    {
        // overloaded parethesis operator gives us access
        // to vector elements (see Board.h)
        if (m_board(row, 0) == m_board(0, 1) &&
            m_board(row, 1) == m_board(row, 2))
        {
            if (m_board(row, 0) == player1)
                return 10;
            else if (m_board(row, 0) == player2)
                return -10;
        }
    }
    for (int col{0}; col < 3; ++col)
    {
        if (m_board(0, col) == m_board(1, col) &&
            m_board(1, col) == m_board(2, col))
        {
            if (m_board(0, col) == player1)
                return 10;
            else if (m_board(0, col) == player2)
                return -10;
        }
    }
    if (m_board(0, 0) == m_board(1, 1) && m_board(1, 1) == m_board(2, 2))
    {
        if (m_board(0, 0) == player1)
            return 10;
        else if (m_board(0, 0) == player2)
            return -10;
    }
    if (m_board(0, 2) == m_board(1, 1) && m_board(1, 1) == m_board(2, 0))
    {
        if (m_board(0, 2) == player1)
            return 10;
        else if (m_board(0, 2) == player2)
            return -10;
    }
    return 0;
}

// https://www.geeksforgeeks.org/dsa/finding-optimal-move-in-tic-tac-toe-using-minimax-algorithm-in-game-theory/
int Game::minimax(int depth, bool isMax)
{
    int score{evaluate()};

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (m_board.hasSpace() == false)
        return 0;

    if (isMax)
    {
        int best{-1000};
        for (int i{0}; i < 3; ++i)
        {
            for (int j{0}; j < 3; ++j)
            {
                if (m_board(i, j) == 0)
                {
                    m_board(i, j) = m_player1.getPlayer().getSymbol();

                    best = std::max(best, minimax(depth + 1, !isMax));

                    m_board(i, j) = 0;
                }
            }
        }
        return best;
    }
    else
    {
        int best{1000};

        for (int i{0}; i < 3; ++i)
        {
            for (int j{0}; j < 3; ++j)
            {
                if (m_board(i, j) == 0)
                {
                    m_board(i, j) = m_player2.getPlayer().getSymbol();

                    best = std::min(best, minimax(depth + 1, !isMax));

                    m_board(i, j) = 0;
                }
            }
        }
        return best;
    }
}

std::pair<int, int> Game::findBestMove()
{
    int bestVal = -1000;
    std::pair<int, int> bestMove{-1, -1};

    for (int i{0}; i < 3; ++i)
    {
        for (int j{0}; j < 3; ++j)
        {
            if (m_board(i, j) == 0)
            {
                m_board(i, j) = m_player1.getPlayer().getSymbol();

                int moveVal = minimax(0, false);

                m_board(i, j) = 0;

                if (moveVal > bestVal)
                {
                    bestMove.first = i;
                    bestMove.second = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// using the result from minmax algorithm
// play opponent move
void Game::opponentMove()
{
    std::pair<int, int> bestMove{findBestMove()};
    // opponent made a move
    makeTurn(bestMove.first, bestMove.second);

    std::cout << "AI Played:\n";
}

void Game::playerWithComputer()
{
    m_board.displayBoard();
    while (m_board.hasSpace())
    {
        char currentPlayerChar = m_currentPlayer->getPlayer().getSymbol();

        if (currentPlayerChar == 'O')
        {
            opponentMove();
        }
        else
        {
            std::size_t x{getUserRow()};
            std::size_t y{getUserCols()};

            makeTurn(x, y);
        }

        m_board.displayBoard();

        if (m_board.checkWin(currentPlayerChar))
        {
            std::cout << currentPlayerChar << " wins!" << '\n';
            return;
        }

        switchCurrPlayer(m_currentPlayer);
    }
    std::cout << "Draw!" << '\n';
}

void Game::playerWithHuman()
{
    m_board.displayBoard();
    while (m_board.hasSpace())
    {
        std::size_t x{getUserRow()};
        std::size_t y{getUserCols()};

        makeTurn(x, y);
        char currentPlayerChar = m_currentPlayer->getPlayer().getSymbol();

        m_board.displayBoard();

        if (m_board.checkWin(currentPlayerChar))
        {
            std::cout << currentPlayerChar << " wins!" << '\n';
            return;
        }

        switchCurrPlayer(m_currentPlayer);
    }
    std::cout << "Draw!" << '\n';
}
