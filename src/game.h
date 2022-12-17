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
    //konstruktor
    Game();
    //destruktor
    ~Game();
    Game(const Game &) = delete;
    //geteri
    Player* getPlayer1() const;
    Player* getPlayer2() const;
    Player* getPlayer3() const;
    Player* getPlayer4() const;
    Player* getCurrentPlayer() const;
    //seteri
    void setPlayer1(Player *player1);
    void setPlayer2(Player *player2);
    void setPlayer3(Player *player3);
    void setPlayer4(Player *player4);
    void setCurrentPlayer(Player *currentPlayer);


    int currentPlayerId() const;
    bool wonPlayer1();
    bool wonPlayer2();
    bool wonPlayer3();
    bool wonPlayer4();





private:
    Player* m_player1;
    Player* m_player2;
    Player* m_player3;
    Player* m_player4;
    Player* m_currentPlayer;
    Board m_board;
    int numOfPlayers = 4;
};

#endif // GAME_H
