#include "game.h"

Game::Game()
    : m_player1(new Player(1, "FirstPlayer"))
    , m_player2(new Player(2, "SecondPlayer"))
    , m_player3(new Player(3, "ThirdPlayer"))
    , m_player4(new Player(4, "FourthPlayer"))
    , m_currentPlayer(m_player1){}
