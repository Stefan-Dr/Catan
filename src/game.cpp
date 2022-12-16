#include "game.h"
#include "player.h"

//konstruktor
Game::Game()
    : m_player1(new Player(1, "FirstPlayer"))
    , m_player2(new Player(2, "SecondPlayer"))
    , m_player3(new Player(3, "ThirdPlayer"))
    , m_player4(new Player(4, "FourthPlayer"))
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


//seteri
void Game::setPlayer1(Player *player1) { m_player2 = player1; }
void Game::setPlayer2(Player *player2) { m_player2 = player2; }
void Game::setPlayer3(Player *player3) { m_player2 = player3; }
void Game::setPlayer4(Player *player4) { m_player2 = player4; }
void Game::setCurrentPlayer(Player *player) { m_currentPlayer = player; }
