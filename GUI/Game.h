#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <qqml.h>

#include "Board.h"
#include "Player.h"

class Game : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QList<QString> board READ board NOTIFY boardChanged)
    Q_PROPERTY(QString status READ status NOTIFY statusChanged)

public:
    explicit Game(QObject* parent = nullptr);
    Q_INVOKABLE void cellClicked(int row, int col);
    QList<QString> board();

    QString status() const;

private:
    void makeTurn(std::size_t x, std::size_t y);
    void switchCurrPlayer(const Player* player);

    Board m_board{};
    Player m_player1{Symbol{'X'}};
    Player m_player2{Symbol{'O'}};
    Player* m_currentPlayer{&m_player1};

signals:
    void boardChanged();
    void statusChanged();

private:
    QString m_status{};
    bool m_gameOver{false};
};

#endif
