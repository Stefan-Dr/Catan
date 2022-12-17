#include "game.h"
#include "player.h"

//konstruktor
//mora da se prosledjuje iz labela u guiu ime igraca
Game::Game()
    : m_player1(new Player(1, ""))
    , m_player2(new Player(2, ""))
    , m_player3(new Player(3, ""))
    , m_player4(new Player(4, ""))
    , m_currentPlayer(m_player1){}

//destruktor
Game::~Game() {
  delete m_player1;
  delete m_player2;
  delete m_player3;
  delete m_player4;
  delete m_currentPlayer;
}

//geteri
Player* Game::getPlayer1() const{
    return m_player1;
}
Player* Game::getPlayer2() const{
    return m_player2;
}
Player* Game::getPlayer3() const{
    return m_player3;
}
Player* Game::getPlayer4() const{
    return m_player4;
}
Player* Game::getCurrentPlayer() const{
    return m_currentPlayer;
}


//seteri
void Game::setPlayer1(Player *player1) {
    m_player1 = player1;
}
void Game::setPlayer2(Player *player2) {
    m_player2 = player2;
}
void Game::setPlayer3(Player *player3) {
    m_player3 = player3;
}
void Game::setPlayer4(Player *player4) {
    m_player4 = player4;
}
void Game::setCurrentPlayer(Player *player) {
    m_currentPlayer = player;
}


auto Game::currentPlayerId() const -> int {
    return m_currentPlayer->get_id();
}

//pobednik partije
bool Game::wonPlayer1() {
  return m_player1->get_victory_points() == 10;
}

bool Game::wonPlayer2() {
  return m_player2->get_victory_points() == 10;
}

bool Game::wonPlayer3() {
 return m_player3->get_victory_points() == 10;
}

bool Game::wonPlayer4() {
 return m_player4->get_victory_points() == 10;
}
