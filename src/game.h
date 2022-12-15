#ifndef GAME_H
#define GAME_H

#include "bank.h"
#include "board.h"
#include "dice.h"
#include "field.h"
#include "player.h"
#include "road.h"

#include <QObject>

class Game
{
public:
    Game();

private:
    Player *m_player1;
    Player *m_player2;
    Player *m_player3;
    Player *m_player4;
    Player *m_currentPlayer;
    Board m_board;
    int numOfPlayers = 4;
};

#endif // GAME_H
