#ifndef GAME_H
#define GAME_H

#include "bank.h"
#include "board.h"
#include "dice.h"
#include "field.h"
#include "player.h"
#include "road.h"
#include "node.h"
#include <vector>

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
    Bank* getBank() const;
    Player* getCurrentPlayer() const;
    QVector<Player*>& get_players();
    //seteri
    void setPlayer1(Player *player1);
    void setPlayer2(Player *player2);
    void setPlayer3(Player *player3);
    void setPlayer4(Player *player4);
    void setBank(Bank* bank);
    void setCurrentPlayer(Player *currentPlayer);


    int currentPlayerId() const;
    bool wonPlayer1();
    bool wonPlayer2();
    bool wonPlayer3();
    bool wonPlayer4();


    void BuildHouse(/*Node* node*/);
    void BuildCity(/*Node* node*/);
    void BuildRoad(/*Road* road*/);

    void firstTurn();
    void secondTurn();
    void Turn(int result, Board* board);
    void ChangeCurrentPlayer();
    void gameResult();
    void nextPlayer();

    void set_can_build_house(bool value);
    void set_can_build_city(bool value);
    bool get_can_build_house() const;
    bool get_can_build_city() const;

    bool can_build_house();
    bool can_build_city();
    bool can_build_road();
    bool can_get_magic_card();

    void dec_resources_house();
    void dec_resources_city();

    void MagicCard();

    int player_turn_counter = 1;

    //treba private
    Player *next_player;
    bool win();
    void setWin(bool x);
private:
    //napraviti niz playera radi lakseg funkcionisanja
    QVector<Player*> m_players;
    Player* m_player1;
    Player* m_player2;
    Player* m_player3;
    Player* m_player4;
    Player* m_currentPlayer;
    Bank* m_bank;
    //Board* m_board;
    int numOfPlayers = 4;
    bool m_can_build_house;
    bool m_can_build_city;
    bool m_win = false;
};

#endif // GAME_H
