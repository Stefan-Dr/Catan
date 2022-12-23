#include "game.h"
#include "player.h"
#include "dice.h"

//konstruktor
//mora da se prosledjuje iz labela u guiu ime igraca
Game::Game()
    : m_player1(new Player(1, ""))
    , m_player2(new Player(2, ""))
    , m_player3(new Player(3, ""))
    , m_player4(new Player(4, ""))
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
    /*
     * Redosled:
     * 1.Bacanje kockice
     * 2.Dodavanje resursa svim igracima na osnovu zauzetih cvorova
     * 3.BuildRoad/BuildHouse/BuildCity
     * 4.Kliktanje dugmeta za kraj poteza
     */

     /*Dice* dice = new Dice();
     dice->roll_dice();
     dice->set_button_is_clicked(true);

     int result = dice->get_dice_sum();*/

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

                                for(auto resource : player->get_PlayerResources()){

                                    if(resource.first == i->get_res_type()){
                                        resource.second++;
                                    }

                                }
                                //nakon sto se pronadje vlasnik i dodele resursi zaustavi se petlja
                                //koja pronalazi igraca koji poseduje objekat na tom cvoru
                                break;
                            }
                        }
                    }
                    if(j->get_is_city_built()){
                        //isto sve samo ovaj put proveravamo da li je na tom polju izgradjen grad
                        for(auto &player : m_players){
                            if(player->get_id() == j->get_owner()){

                                for(auto resource : player->get_PlayerResources()){

                                    if(resource.first == i->get_res_type()){
                                        resource.second += 2;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
     }

     //opcije za izgradnju objekata

         //if(kliknuto dugme za izgradnju kucice){
             for(auto node : board->m_nodes){
                 //u petlji prveravamo da li je taj cvor kliknut
                 //if(kliknut cvor)
                 if(!node->get_is_house_built()){
                 //ako jeste na tom cvoru postavljamo kucicu
                 BuildHouse(node);
                 }
             }

         //if(kliknuto dugme za izgradnju grada){
               for(auto node : board->m_nodes){
                   //u petlji trazimo cvor koji je kliknuo igrac i na tom polju gradimo grad
                    //if(kliknut cvor)
                    if(node->get_is_house_built()){
                        BuildCity(node);
                    }
               }
        /*
         * ne moze da se pokrene dokle god se ne zavrsi klasa road
         if(kliknuto dugme za izgradnju puta){
               if(cvor1 je kliknut){
                  for(auto node1: board->m_nodes){
                     for(auto node2: node1->get_neighbours()){
                       if(cvor2 je klinut){
                          if(node->get_can_build()){
                              BuildRoad(road);
                          }
                       }
                     }
                  }
               }
         }

        */


}

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


