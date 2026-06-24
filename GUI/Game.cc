#include <QDebug>
#include <cstddef>

#include "Game.h"

Game::Game(QObject* parent) : QObject{parent} {}

void Game::makeTurn(std::size_t row, std::size_t col)
{
    m_board.setSymbol(row, col, m_currentPlayer->getPlayer());
}

void Game::switchCurrPlayer()
{
    m_currentPlayer =
        ((m_currentPlayer == &m_player1) ? &m_player2 : &m_player1);
}

QString Game::status() const { return m_status; }

// used to flatten m_board
// converts 0s to ""
QList<QString> Game::board()
{
    QList<QString> result{};
    for (int i{0}; i < 9; ++i)
    {
        char c = m_board(i / 3, i % 3);
        result.append(c == 0 ? "" : QString(c));
    }

    return result;
}

void Game::cellClickedVsHuman(int row, int col)
{
    makeTurn(row, col);
    char currentPlayerChar = m_currentPlayer->getPlayer().getSymbol();

    if (m_gameOver)
        return;

    if (m_board.checkWin(currentPlayerChar))
    {
        m_status = QString(currentPlayerChar) + " wins!";
        m_gameOver = true;
        emit boardChanged();
        emit statusChanged();
        return;
    }
    if (!m_board.hasSpace())
    {
        m_status = "Draw";
        m_gameOver = true;
        emit boardChanged();
        emit statusChanged();
        return;
    }

    switchCurrPlayer();

    emit boardChanged();
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
}

void Game::cellClickedVsAI(int row, int col)
{
    if (m_gameOver)
        return;

    makeTurn(row, col);

    if (m_board.checkWin('X'))
    {
        m_status = QString('X') + " wins!";
        m_gameOver = true;
        emit boardChanged();
        emit statusChanged();
        return;
    }
    if (!m_board.hasSpace())
    {
        m_status = "Draw";
        m_gameOver = true;
        emit boardChanged();
        emit statusChanged();
        return;
    }

    switchCurrPlayer();

    // immediately do the opponents move
    opponentMove();

    // need to check if the AI has won or not
    if (m_board.checkWin('O'))
    {
        m_status = QString('O') + " wins!";
        m_gameOver = true;
        emit boardChanged();
        emit statusChanged();
        return;
    }

    switchCurrPlayer();

    emit boardChanged();
}

void Game::resetBoard()
{
    m_currentPlayer->setPlayer('X');
    m_gameOver = false;
    m_status = {};

    for (int i{0}; i < 3; ++i)
    {
        for (int j{0}; j < 3; ++j)
        {
            m_board(i, j) = 0;
        }
    }
    emit boardChanged();
    emit statusChanged();
}
