#include "game.h"
#include "player.h"
#include "dice.h"
#include <algorithm>
#include "resourcetype.h"

//konstruktor
//mora da se prosledjuje iz labela u guiu ime igraca
Game::Game()
    : m_player1(new Player(1, "", Qt::blue, Qt::darkBlue))
    , m_player2(new Player(2, "", Qt::yellow, Qt::darkYellow))
    , m_player3(new Player(3, "", Qt::green,  Qt::darkGreen))
    , m_player4(new Player(4, "", Qt::red, Qt::darkRed))
    , m_currentPlayer(m_player1)
    , m_bank(new Bank())
    /*, m_board(new Board())*/{}


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

QVector<Player*>& Game::get_players(){
    return m_players;
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

void Game::BuildHouse(/*Node* node*/){
    //if(m_currentPlayer->get_num_of_allowed_houses() > 0){
        //ZAKOMENTARISANO
//        if(node->get_can_build() == true){
//            if(m_currentPlayer->get_num_of_wood() >= 1 &&
//               m_currentPlayer->get_num_of_wool() >= 1 &&
//               m_currentPlayer->get_num_of_wheat() >= 1 &&
//               m_currentPlayer->get_num_of_brick() >= 1){

                //node->place_house(m_currentPlayer->get_id());

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

        //}
        //}
   //}
}

void Game::BuildCity(/*Node* node*/){


//    if(node->get_can_build_city() == true){
//        if(m_currentPlayer->get_num_of_wheat() >= 2 &&
//           m_currentPlayer->get_num_of_stone() >= 3){

//            node->place_city(m_currentPlayer->get_id());

            m_currentPlayer->return_resource_card_to_bank(ResourceType::Wheat,2,*m_bank);
            m_currentPlayer->return_resource_card_to_bank(ResourceType::Stone,3,*m_bank);

            m_currentPlayer->increase_allowed_house_number();
            m_currentPlayer->decrease_allowed_city_number();
            m_currentPlayer->increase_victory_points();

            //menjanje broja izgradjenih objekata
            m_currentPlayer->decrease_num_of_houses();
            m_currentPlayer->increase_num_of_cities();

            //graficko postavljanje grada


//        }
//    }

}

void Game::BuildRoad(/*Road* road*/){

//    if(m_currentPlayer->get_num_of_brick() >= 1 &&
//       m_currentPlayer->get_num_of_wood() >= 1){

//        road->set_owner(m_currentPlayer->get_id());

        m_currentPlayer->return_resource_card_to_bank(ResourceType::Brick,1,*m_bank);
        m_currentPlayer->return_resource_card_to_bank(ResourceType::Wood,1,*m_bank);

        m_currentPlayer->decrease_allowed_road_number();

        //menjanje broja izgradjenih objekata
        m_currentPlayer->increase_num_of_roads();

        //graficko postavljanje puta
//    }

}

//Da li cemo bacati kockice i odredjivati ko igra prvi, ili cemo ici redom po igracima?


void Game::firstTurn(){
    //redosled igraca je od 1 do 4
    //postavljanje jedne kuce
    //postavljanje jednog puta


}

void Game::secondTurn(){
    //redosled igraca je od 4 do 1
    //postavljanje jedne kuce
    //postavljanje jednog puta
    //dobijanje resursa u zavisnosti gde je postavljena druga kuca


}



void Game::Turn(int result, Board* board){


     for(auto &i : board->m_fields){
         //prolazimo kroz sva polja na tabli
        if(result == i->get_number()){
            //proveravamo da li trenutno polje sadzi broj koji je jednak zbiru bacenih kockica
            if(!i->is_robber_on_the_field()){
                //ako se na tom polju ne nalazi lopov radimo sledece
                for(auto j : i->get_corners()){
                    //prolazimo kroz sve cvorove na tom polju
                    if(j->get_is_house_built()){
                        //proveravamo da li ima izgradjena kucica na tom cvoru
                        for(auto &player : m_players){
                            //u petlji sada za svakog igraca proveravamo da li se njegov id poklapa sa id-em onog igraca koji ima objekat na tom cvoru
                            if(player->get_id() == j->get_owner()){

                                if(i->get_res_type() == ResourceType::Brick){
                                    player->inc_num_of_brick();
                                    m_bank->remove_resource_card(ResourceType::Brick,1);
                                }
                                else if(i->get_res_type() == ResourceType::Stone){
                                    player->inc_num_of_stone();
                                    m_bank->remove_resource_card(ResourceType::Stone,1);
                                }
                                else if(i->get_res_type() == ResourceType::Wheat){
                                    player->inc_num_of_wheat();
                                    m_bank->remove_resource_card(ResourceType::Wheat,1);
                                }
                                else if(i->get_res_type() == ResourceType::Wood){
                                    player->inc_num_of_wood();
                                    m_bank->remove_resource_card(ResourceType::Wood,1);
                                }
                                else{
                                    player->inc_num_of_wool();
                                    m_bank->remove_resource_card(ResourceType::Wool,1);
                                }
                                //nakon sto se pronadje vlasnik i dodele resursi zaustavi se petlja
                                //koja pronalazi igraca koji poseduje objekat na tom cvoru

                            }
                        }
                    }
                    if(j->get_is_city_built()){
                        //isto sve samo ovaj put proveravamo da li je na tom polju izgradjen grad
                        for(auto &player : m_players){
                            if(player->get_id() == j->get_owner()){
                                if(i->get_res_type() == ResourceType::Brick){
                                    player->double_inc_num_of_brick();
                                    m_bank->remove_resource_card(ResourceType::Brick,2);
                                }
                                else if(i->get_res_type() == ResourceType::Stone){
                                    player->double_inc_num_of_stone();
                                    m_bank->remove_resource_card(ResourceType::Stone,2);
                                }
                                else if(i->get_res_type() == ResourceType::Wheat){
                                    player->double_inc_num_of_wheat();
                                    m_bank->remove_resource_card(ResourceType::Wheat,2);
                                }
                                else if(i->get_res_type() == ResourceType::Wood){
                                    player->double_inc_num_of_wood();
                                    m_bank->remove_resource_card(ResourceType::Wood,2);
                                }
                                else{
                                    player->double_inc_num_of_wool();
                                    m_bank->remove_resource_card(ResourceType::Wool,2);
                                }

                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}


//}

void Game::ChangeCurrentPlayer(){
    if(m_currentPlayer->get_id() == m_player1->get_id()){
        m_currentPlayer = m_player2;
    }
    else if(m_currentPlayer->get_id() == m_player2->get_id()){
        m_currentPlayer = m_player3;
    }
    else if(m_currentPlayer->get_id() == m_player3->get_id()){
        m_currentPlayer = m_player4;
    }
    else if(m_currentPlayer->get_id() == m_player4->get_id()){
        m_currentPlayer = m_player1;
    }
}




void Game::gameResult(){

      Player* players[] = { m_player1,
                            m_player2,
                            m_player3,
                            m_player4  };

      int numPlayers = sizeof(players) / sizeof(players[0]);

      //std::sort(players, players + numPlayers, comparePlayers);
      //prosledjivanje pokazivaca na fukcniju???


      for (int i = 0; i < numPlayers; i++) {
        std::cout << "Player " << i + 1 << ": " << players[i]->get_victory_points() << " points" << std::endl;
      }


    /*
     * pokusaj sortiranja
    players.push_back(m_player1);
    players.push_back(m_player2);
    players.push_back(m_player3);
    players.push_back(m_player4);

    QVector<int> players_points = {
            players[0]->get_victory_points(),
            players[1]->get_victory_points(),
            players[2]->get_victory_points(),
            players[3]->get_victory_points()
    };


    Player* first;
    Player* second;
    Player* third;
    Player* fourth;

    int n = sizeof(players);

    std::sort(players_points.begin(), players_points.end());
    //sortiranje na osnovu broja ostvarenih poena???
    for(int i = 0; i < players_points.size(); i++){
        first = players[4];
        second = players[3];
        third = players[2];
        fourth = players[1];

    }

    std::cout << "First: " << first << std::endl;

    std::cout << "Second: " << second << std::endl;

    std::cout << "Third: " << third << std::endl;

    std::cout << "Fourth: " << fourth << std::endl;
    */

}

void Game::nextPlayer()
{
    if (getCurrentPlayer() == m_player1 )   { setCurrentPlayer(m_player2); }
    else if (getCurrentPlayer() == m_player2 )   { setCurrentPlayer(m_player3); }
    else if (getCurrentPlayer() == m_player3 )   { setCurrentPlayer(m_player4); }
    else  { setCurrentPlayer(m_player1); }
}

void Game::set_can_build_house(bool value)
{
    m_can_build_house = value;
}

void Game::set_can_build_city(bool value)
{
    m_can_build_city = value;
}

bool Game::get_can_build_house() const
{
    return m_can_build_house;
}

bool Game::get_can_build_city() const
{
    return m_can_build_city;
}

bool Game::can_build_house()
{
    if(m_currentPlayer->get_num_of_wood() >= 1 &&
                   m_currentPlayer->get_num_of_wool() >= 1 &&
                   m_currentPlayer->get_num_of_wheat() >= 1 &&
                   m_currentPlayer->get_num_of_brick() >= 1) { return true; }
    else return false;
}

bool Game::can_build_city()
{
    if(m_currentPlayer->get_num_of_wheat() >= 2 &&
       m_currentPlayer->get_num_of_stone() >= 3) { return true; }
    else return false;
}

bool Game::can_build_road()
{
    if ( m_currentPlayer->get_num_of_wood() >= 1 &&
         m_currentPlayer->get_num_of_brick() >= 1) { return true; }
    else return false;
}

void Game::dec_resources_house()
{



}

void Game::dec_resources_city()
{

}

