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
#include "resourcetype.h"

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

    bool get_can_build_house() const;
    bool get_can_build_city() const;

    //seteri
    void setPlayer1(Player *player1);
    void setPlayer2(Player *player2);
    void setPlayer3(Player *player3);
    void setPlayer4(Player *player4);
    void setBank(Bank* bank);
    void setCurrentPlayer(Player *currentPlayer);
    void set_can_build_house(bool value);
    void set_can_build_city(bool value);
    void setWin(bool x);

    bool wonPlayer1();
    bool wonPlayer2();
    bool wonPlayer3();
    bool wonPlayer4();

    void BuildHouse();
    void BuildCity();
    void BuildRoad();

    void firstTurn();
    void secondTurn();
    void Turn(int result, Board* board);
    void ChangeCurrentPlayer();
    void gameResult();
    void nextPlayer();

    bool can_build_house();
    bool can_build_city();
    bool can_build_road();
    bool can_get_magic_card();

    void dec_resources_house();
    void dec_resources_city();

    void MagicCard();
    int currentPlayerId() const;

    int player_turn_counter = 1;

    bool can_trade_with_bank(ResourceType player_resource, ResourceType bank_resource);
    void trade_with_bank(ResourceType player_resource, ResourceType bank_resource);

    Player *next_player;
    bool win();

private:

    QVector<Player*> m_players;
    Player* m_player1;
    Player* m_player2;
    Player* m_player3;
    Player* m_player4;
    Player* m_currentPlayer;
    Bank* m_bank;

    int numOfPlayers = 4;
    bool m_can_build_house;
    bool m_can_build_city;
    bool m_win = false;
};

#endif // GAME_H
