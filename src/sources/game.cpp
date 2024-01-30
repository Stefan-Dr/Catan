#include "../headers/game.h"

#include <algorithm>
#include <vector>

#include "../headers/dice.h"
#include "../headers/player.h"
#include "../headers/resourcetype.h"

// constructor
Game::Game()
    : m_player1(new Player(1, "", Qt::blue, Qt::darkBlue)),
      m_player2(new Player(2, "", Qt::yellow, Qt::darkYellow)),
      m_player3(new Player(3, "", Qt::green, Qt::darkGreen)),
      m_player4(new Player(4, "", Qt::red, Qt::darkRed)),
      m_currentPlayer(m_player1),
      m_bank(new Bank())
/*, m_board(new Board())*/ {
  m_players = {m_player1, m_player2, m_player3, m_player4};
  m_can_build_city = false;
  m_can_build_house = false;
}

// destructor
Game::~Game() {
  delete m_player1;
  delete m_player2;
  delete m_player3;
  delete m_player4;
  delete m_currentPlayer;
  delete m_bank;

}


// getters
Player *Game::getPlayer1() const { return m_player1; }
Player *Game::getPlayer2() const { return m_player2; }
Player *Game::getPlayer3() const { return m_player3; }
Player *Game::getPlayer4() const { return m_player4; }
Bank *Game::getBank() const { return m_bank; }
Player *Game::getCurrentPlayer() const { return m_currentPlayer; }

QVector<Player *> &Game::get_players() { return m_players; }

// setters
void Game::setPlayer1(Player *player1) { m_player1 = player1; }
void Game::setPlayer2(Player *player2) { m_player2 = player2; }
void Game::setPlayer3(Player *player3) { m_player3 = player3; }
void Game::setPlayer4(Player *player4) { m_player4 = player4; }
void Game::setBank(Bank *bank) { m_bank = bank; }
void Game::setCurrentPlayer(Player *player) { m_currentPlayer = player; }

auto Game::currentPlayerId() const -> int { return m_currentPlayer->get_id(); }

bool Game::wonPlayer1() { return m_player1->get_victory_points() == 10; }

bool Game::wonPlayer2() { return m_player2->get_victory_points() == 10; }

bool Game::wonPlayer3() { return m_player3->get_victory_points() == 10; }

bool Game::wonPlayer4() { return m_player4->get_victory_points() == 10; }

bool Game::win() { return m_win; }

void Game::setWin(bool x) { m_win = x; }

void Game::BuildHouse(/*Node* node*/) {
  // davanje potrebnih resursa banci
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wood, 1, *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Brick, 1,
                                                *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wheat, 1,
                                                *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wool, 1, *m_bank);

  // menja broj dostupnih objekata
  m_currentPlayer->increase_allowed_house_number();
  // m_currentPlayer->increase_victory_points(1);

  // menjanje broja izgradjenih objekata
  m_currentPlayer->increase_num_of_houses();

  m_currentPlayer->increase_victory_points(1);
  if (m_currentPlayer->get_victory_points() >= 10) {
    setWin(true);
  }
}

void Game::BuildCity(/*Node* node*/) {
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wheat, 2,
                                                *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Stone, 3,
                                                *m_bank);

  m_currentPlayer->increase_allowed_house_number();
  m_currentPlayer->decrease_allowed_city_number();
  m_currentPlayer->increase_victory_points(1);

  // menjanje broja izgradjenih objekata
  m_currentPlayer->decrease_num_of_houses();
  m_currentPlayer->increase_num_of_cities();
  if (m_currentPlayer->get_victory_points() >= 10) {
    setWin(true);
  }
}

void Game::BuildRoad(/*Road* road*/) {
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Brick, 1,
                                                *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wood, 1, *m_bank);

  m_currentPlayer->decrease_allowed_road_number();

  // menjanje broja izgradjenih objekata
  m_currentPlayer->increase_num_of_roads();
  if (m_currentPlayer->get_num_of_roads() == 7) {
    m_currentPlayer->increase_victory_points(2);
  }
  if (m_currentPlayer->get_victory_points() >= 10) {
    setWin(true);
  }
}

void Game::MagicCard() {
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wheat, 1,
                                                *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Stone, 1,
                                                *m_bank);
  m_currentPlayer->return_resource_card_to_bank(ResourceType::Wool, 1, *m_bank);
  m_currentPlayer->increase_victory_points(1);
  if (m_currentPlayer->get_victory_points() >= 10) {
    setWin(true);
  }
}

bool Game::can_trade_with_bank(ResourceType player_resource,
                               ResourceType bank_resource) {
  int num_player_resource = 0;
  if (player_resource == ResourceType::Wheat) {
    num_player_resource = getCurrentPlayer()->get_num_of_wheat();
  }
  if (player_resource == ResourceType::Wool) {
    num_player_resource = getCurrentPlayer()->get_num_of_wool();
  }
  if (player_resource == ResourceType::Stone) {
    num_player_resource = getCurrentPlayer()->get_num_of_stone();
  }
  if (player_resource == ResourceType::Wood) {
    num_player_resource = getCurrentPlayer()->get_num_of_wood();
  }
  if (player_resource == ResourceType::Brick) {
    num_player_resource = getCurrentPlayer()->get_num_of_brick();
  }

  int num_bank_resource = 0;
  if (bank_resource == ResourceType::Wheat) {
    num_bank_resource = getBank()->get_num_of_wheat_from_bank();
  }
  if (bank_resource == ResourceType::Wool) {
    num_bank_resource = getBank()->get_num_of_wool_from_bank();
  }
  if (bank_resource == ResourceType::Stone) {
    num_bank_resource = getBank()->get_num_of_stone_from_bank();
  }
  if (bank_resource == ResourceType::Wood) {
    num_bank_resource = getBank()->get_num_of_wood_from_bank();
  }
  if (bank_resource == ResourceType::Brick) {
    num_bank_resource = getBank()->get_num_of_brick_from_bank();
  }

  if ((num_player_resource >= 3) && (num_bank_resource >= 1)) {
    return true;
  } else
    return false;
}

void Game::trade_with_bank(ResourceType player_resource,
                           ResourceType bank_resource) {
  m_currentPlayer->return_resource_card_to_bank(player_resource, 3, *m_bank);
  m_currentPlayer->take_resource_card_from_bank(bank_resource, 1, *m_bank);
}

void Game::Turn(int result, Board *board) {
  // std::cout <<result << std::endl;
  for (auto &i : board->m_fields) {
    // prolazimo kroz sva polja na tabli
    if (result == i->get_number()) {
      // proveravamo da li trenutno polje sadzi broj koji je jednak zbiru
      // bacenih kockica if(!i->is_robber_on_the_field()){ ako se na tom
      // polju ne nalazi lopov radimo sledece std::cout << i->get_id() <<
      // std::endl;
      for (auto &j : i->get_corners()) {
        // prolazimo kroz sve cvorove na tom polju
        // std::cout << j->get_is_house_built() << std::endl;
        if (j->get_is_house_built()) {
          // std::cout << j->get_id() << std::endl;
          // proveravamo da li ima izgradjena kucica na tom cvoru
          // std::cout << j->get_owner() << std::endl;
          if (i->get_res_type() == ResourceType::Brick) {
            m_players[j->get_owner() - 1]->inc_num_of_brick();
            m_bank->remove_resource_card(ResourceType::Brick, 1);
          } else if (i->get_res_type() == ResourceType::Stone) {
            m_players[j->get_owner() - 1]->inc_num_of_stone();
            m_bank->remove_resource_card(ResourceType::Stone, 1);
          } else if (i->get_res_type() == ResourceType::Wheat) {
            m_players[j->get_owner() - 1]->inc_num_of_wheat();
            m_bank->remove_resource_card(ResourceType::Wheat, 1);
          } else if (i->get_res_type() == ResourceType::Wood) {
            m_players[j->get_owner() - 1]->inc_num_of_wood();
            m_bank->remove_resource_card(ResourceType::Wood, 1);
          } else {
            m_players[j->get_owner() - 1]->inc_num_of_wool();
            m_bank->remove_resource_card(ResourceType::Wool, 1);
          }
        }
        if (j->get_is_city_built()) {
          if (i->get_res_type() == ResourceType::Brick) {
            m_players[j->get_owner() - 1]->double_inc_num_of_brick();
            m_bank->remove_resource_card(ResourceType::Brick, 2);
          } else if (i->get_res_type() == ResourceType::Stone) {
            m_players[j->get_owner() - 1]->double_inc_num_of_stone();
            m_bank->remove_resource_card(ResourceType::Stone, 2);
          } else if (i->get_res_type() == ResourceType::Wheat) {
            m_players[j->get_owner() - 1]->double_inc_num_of_wheat();
            m_bank->remove_resource_card(ResourceType::Wheat, 2);
          } else if (i->get_res_type() == ResourceType::Wood) {
            m_players[j->get_owner() - 1]->double_inc_num_of_wood();
            m_bank->remove_resource_card(ResourceType::Wood, 2);
          } else {
            m_players[j->get_owner() - 1]->double_inc_num_of_wool();
            m_bank->remove_resource_card(ResourceType::Wool, 2);
          }
        }
      }
    }
  }
}

void Game::ChangeCurrentPlayer() {
  if (m_currentPlayer->get_id() == m_player1->get_id()) {
    m_currentPlayer = m_player2;
  } else if (m_currentPlayer->get_id() == m_player2->get_id()) {
    m_currentPlayer = m_player3;
  } else if (m_currentPlayer->get_id() == m_player3->get_id()) {
    m_currentPlayer = m_player4;
  } else if (m_currentPlayer->get_id() == m_player4->get_id()) {
    m_currentPlayer = m_player1;
  }
}

void Game::gameResult() {
  Player *players[] = {m_player1, m_player2, m_player3, m_player4};

  int numPlayers = sizeof(players) / sizeof(players[0]);

  // std::sort(players, players + numPlayers, comparePlayers);

  for (int i = 0; i < numPlayers; i++) {
    // std::cout << "Player " << i + 1 << ": " <<
    // players[i]->get_victory_points() << " points" << std::endl;
  }
}

void Game::nextPlayer() {
  if (getCurrentPlayer() == m_player1) {
    setCurrentPlayer(m_player2);
  } else if (getCurrentPlayer() == m_player2) {
    setCurrentPlayer(m_player3);
  } else if (getCurrentPlayer() == m_player3) {
    setCurrentPlayer(m_player4);
  } else {
    setCurrentPlayer(m_player1);
  }
}

void Game::set_can_build_house(bool value) { m_can_build_house = value; }

void Game::set_can_build_city(bool value) { m_can_build_city = value; }

bool Game::get_can_build_house() const { return m_can_build_house; }

bool Game::get_can_build_city() const { return m_can_build_city; }

bool Game::can_build_house() {
  if (m_currentPlayer->get_num_of_wood() >= 1 &&
      m_currentPlayer->get_num_of_wool() >= 1 &&
      m_currentPlayer->get_num_of_wheat() >= 1 &&
      m_currentPlayer->get_num_of_brick() >= 1) {
    return true;
  } else
    return false;
}

bool Game::can_build_city() {
  if (m_currentPlayer->get_num_of_wheat() >= 2 &&
      m_currentPlayer->get_num_of_stone() >= 3) {
    return true;
  } else
    return false;
}

bool Game::can_get_magic_card() {
  if (m_currentPlayer->get_num_of_stone() >= 1 &&
      m_currentPlayer->get_num_of_wheat() >= 1 &&
      m_currentPlayer->get_num_of_wool() >= 1) {
    return true;
  } else
    return false;
}

bool Game::can_build_road() {
  if (m_currentPlayer->get_num_of_wood() >= 1 &&
      m_currentPlayer->get_num_of_brick() >= 1) {
    return true;
  } else
    return false;
}
