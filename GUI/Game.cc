#include <QDebug>
#include <cstddef>

#include "Game.h"

Game::Game(QObject* parent) : QObject{parent} {}

void Game::makeTurn(std::size_t row, std::size_t col)
{
    m_board.setSymbol(row, col, m_currentPlayer->getPlayer());
}

void Game::switchCurrPlayer(const Player* currPlayer)
{
    m_currentPlayer = ((currPlayer == &m_player1) ? &m_player2 : &m_player1);
}

QString Game::status() const { return m_status; }

// used to flatten m_board
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

void Game::cellClicked(int row, int col)
{
    makeTurn(row, col);
    char currentPlayerChar = m_currentPlayer->getPlayer().getSymbol();

    if (m_board.checkWin(currentPlayerChar))
    {
        m_status = QString(currentPlayerChar) + " wins!";
        emit boardChanged();
        emit statusChanged();
        return;
    }
    if (!m_board.hasSpace())
    {
        m_status = "Draw";
        emit boardChanged();
        emit statusChanged();
        return;
    }

    switchCurrPlayer(m_currentPlayer);
    emit boardChanged();
}
