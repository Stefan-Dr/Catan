#ifndef PLAYER_H
#define PLAYER_H
#include <unordered_map>
#include <vector>

#include "bank.h"
#include "resourcetype.h"
#include "color.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Player
{
public:
    Player();
    Player(const Player& ) = delete;
    Player(int id, std::string name, Color);

    const std::string &get_name();
    Color get_color() const;
    int get_victory_points() const;
    int get_num_of_houses() const;
    int get_num_of_cities() const;
    int get_num_of_roads() const;

    void set_city(Bank &bank);

    bool give_resource_card_to_player(ResourceType res_type, int amount, Player &p);
    bool take_resource_card_from_bank(ResourceType res_type, int amount, Bank &bank);

    bool return_resource_card_to_bank(ResourceType res_type, int amount, Bank &bank);
    std::unordered_map<ResourceType,int> get_PlayerResources();
    void set_PlayerResources(const std::unordered_map<ResourceType,int> &mPlayerResource);
    void increase_victory_points();
    void increase_house_number();
    void decrease_house_number();
    void decrease_city_number();
    void decrease_road_number();
    void decrease_victory_point();

    /*void set_city(Bank); set_house(NOde,Bank), set_road(road,NOde,Bank);..*/

private:
    int m_id;
    std::string m_name;
    Color m_color;
    int m_victory_points;
    int m_num_of_roads;
    int m_num_of_houses;
    int m_num_of_cities;
    std::unordered_map<ResourceType, int> m_player_resource;
    int m_num_of_allowed_houses;
    int m_num_of_allowed_cities;
    int m_num_of_allowed_roads;


};

#endif // PLAYER_H
