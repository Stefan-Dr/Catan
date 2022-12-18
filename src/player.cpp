#include "player.h"
#include <iostream>

Player::Player()
{

}
Player::Player(int id, std::string name/*, Color color*treba ovo da se doradi*/)
    : m_id(id), m_name(name),/*m_color(color),*/
      m_victory_points(0),m_num_of_roads(0),
      m_num_of_houses(0),m_num_of_cities(0),m_num_of_allowed_houses(5),
      m_num_of_allowed_cities(4),m_num_of_allowed_roads(15){

      m_player_resource[ResourceType::Brick] = 0;
      m_player_resource[ResourceType::Stone] = 0;
      m_player_resource[ResourceType::Wheat] = 0;
      m_player_resource[ResourceType::Wood] = 0;
      m_player_resource[ResourceType::Wool] = 0;



}

/*Color Player::get_color(){
    return m_color;
}
*/

int Player::get_num_of_wood() const {
    return m_num_of_wood;
}
int Player::get_num_of_brick() const {
    return m_num_of_brick;
}
int Player::get_num_of_wool() const {
    return m_num_of_wool;
}
int Player::get_num_of_wheat() const {
    return m_num_of_wheat;
}
int Player::get_num_of_stone() const {
    return m_num_of_stone;
}

int Player::get_num_of_allowed_houses() const{
    return m_num_of_allowed_houses;
}
int Player::get_num_of_allowed_cities() const{
    return m_num_of_allowed_cities;
}
int Player::get_num_of_allowed_roads() const{
    return m_num_of_allowed_roads;
}

int Player::get_id() const{
    return m_id;
}

int Player::get_victory_points() const{
    return m_victory_points;
}
int Player::get_num_of_houses() const{
    return m_num_of_houses;
}
int Player::get_num_of_cities() const{
    return m_num_of_cities;
}
int Player::get_num_of_roads() const{
    return m_num_of_roads;
}
std::unordered_map<ResourceType,int> Player::get_PlayerResources(){
    return m_player_resource;
}
void Player::set_PlayerResources(const std::unordered_map<ResourceType,int> &mPlayerResource){
    m_player_resource = mPlayerResource;
}

bool Player::give_resource_card_to_player(ResourceType res_type, int amount, Player &p){
    if(m_player_resource[res_type]<amount){
        return false;
    }
    m_player_resource[res_type] -= amount;
    auto p2_resources = p.get_PlayerResources();
    p2_resources[res_type] += amount;
    p.set_PlayerResources(p2_resources);
    return true;
}
void Player::take_resource_card_from_bank(ResourceType res_type, int amount, Bank &bank){
 m_player_resource[res_type]+=amount;
 bank.remove_resource_card(res_type,amount);

}

void Player::return_resource_card_to_bank(ResourceType res_type, int amount, Bank &bank){
    m_player_resource[res_type]-=amount;
    bank.add_resource_card(res_type,amount);

}


void Player::increase_num_of_houses(){
    m_num_of_houses++;
}
void Player::decrease_num_of_houses(){
    m_num_of_houses--;
}
void Player::increase_num_of_cities(){
    m_num_of_cities++;
}
void Player::increase_num_of_roads(){
    m_num_of_roads++;
}

void Player::increase_victory_points(){
    m_victory_points++;
}
void Player::increase_allowed_house_number(){
    m_num_of_allowed_houses++;
}
void Player::decrease_allowed_house_number(){
    m_num_of_allowed_houses--;
}
//allowed promeni na to
void Player::decrease_allowed_city_number(){
   m_num_of_allowed_cities--;
}
void Player::decrease_allowed_road_number(){
    m_num_of_allowed_roads--;
}
void Player::decrease_victory_point(){
    m_victory_points--;
}

