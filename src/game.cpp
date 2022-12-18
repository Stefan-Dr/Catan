#include "game.h"
#include "player.h"


//konstruktor
//mora da se prosledjuje iz labela u guiu ime igraca
Game::Game()
    : m_player1(new Player(1, ""))
    , m_player2(new Player(2, ""))
    , m_player3(new Player(3, ""))
    , m_player4(new Player(4, ""))
    , m_currentPlayer(m_player1)
    , m_bank(new Bank()){}


//destruktor
Game::~Game() {
  delete m_player1;
  delete m_player2;
  delete m_player3;
  delete m_player4;
  delete m_currentPlayer;
  delete m_bank;
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
Bank* Game::getBank() const{
    return m_bank;
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
void Game::setBank(Bank* bank){
    m_bank = bank;
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

//izgradnja

void Game::BuildHouse(Node* node){
    if(m_currentPlayer->get_num_of_allowed_houses() > 0){
        if(node->get_can_build() == true){
            if(m_currentPlayer->get_num_of_wood() >= 1 &&
               m_currentPlayer->get_num_of_wool() >= 1 &&
               m_currentPlayer->get_num_of_wheat() >= 1 &&
               m_currentPlayer->get_num_of_brick() >= 1){

                node->place_house(m_currentPlayer->get_id());

                //davanje potrebnih resursa banci
                m_currentPlayer->return_resource_card_to_bank(ResourceType::Wood,1,*m_bank);
                m_currentPlayer->return_resource_card_to_bank(ResourceType::Brick,1,*m_bank);
                m_currentPlayer->return_resource_card_to_bank(ResourceType::Wheat,1,*m_bank);
                m_currentPlayer->return_resource_card_to_bank(ResourceType::Wool,1,*m_bank);

                //menja broj dostupnih objekata
                m_currentPlayer->increase_allowed_house_number();
                m_currentPlayer->increase_victory_points();

                //menjanje broja izgradjenih objekata
                m_currentPlayer->increase_num_of_houses();
                //graficko postavljanje kuce


            }

        }
   }
}

void Game::BuildCity(Node* node){


    if(node->get_can_build() == true){
        if(m_currentPlayer->get_num_of_wheat() >= 2 &&
           m_currentPlayer->get_num_of_stone() >= 3){

            node->place_city(m_currentPlayer->get_id());

            m_currentPlayer->return_resource_card_to_bank(ResourceType::Wheat,2,*m_bank);
            m_currentPlayer->return_resource_card_to_bank(ResourceType::Stone,3,*m_bank);

            m_currentPlayer->increase_allowed_house_number();
            m_currentPlayer->decrease_allowed_city_number();
            m_currentPlayer->increase_victory_points();

            //menjanje broja izgradjenih objekata
            m_currentPlayer->decrease_num_of_houses();
            m_currentPlayer->increase_num_of_cities();

            //graficko postavljanje grada


        }
    }

}

void Game::BuildRoad(Road* road){

    if(m_currentPlayer->get_num_of_brick() >= 1 &&
       m_currentPlayer->get_num_of_wood() >= 1){

        road->set_owner(m_currentPlayer->get_id());

        m_currentPlayer->return_resource_card_to_bank(ResourceType::Brick,1,*m_bank);
        m_currentPlayer->return_resource_card_to_bank(ResourceType::Wood,1,*m_bank);

        m_currentPlayer->decrease_allowed_road_number();

        //menjanje broja izgradjenih objekata
        m_currentPlayer->increase_num_of_roads();

        //graficko postavljanje puta
    }

}
