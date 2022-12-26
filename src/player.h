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
    Player(int id, std::string name, QColor color, QColor color_c /*Color*/);

    const std::string &get_name();
    int get_id() const;
    Color get_color() const;
    int get_victory_points() const;
    int get_num_of_houses() const;
    int get_num_of_cities() const;
    int get_num_of_roads() const;

    int get_num_of_wood() const;
    int get_num_of_brick() const;
    int get_num_of_wool() const;
    int get_num_of_wheat() const;
    int get_num_of_stone() const;

    void inc_num_of_wood();
    void inc_num_of_wheat();
    void inc_num_of_stone();
    void inc_num_of_brick();
    void inc_num_of_wool();
    void dec_num_of_wood();
    void dec_num_of_wheat();
    void dec_num_of_stone();
    void dec_num_of_brick();
    void dec_num_of_wool();

    void double_inc_num_of_wood();
    void double_inc_num_of_wheat();
    void double_inc_num_of_stone();
    void double_inc_num_of_brick();
    void double_inc_num_of_wool();

    int get_num_of_allowed_houses() const;
    int get_num_of_allowed_cities() const;
    int get_num_of_allowed_roads() const;
    QColor get_player_color() const;
    QColor get_city_color() const;

    void set_city(Bank &bank);
    void set_id(int id);

    bool give_resource_card_to_player(ResourceType res_type, int amount, Player &p);
    void take_resource_card_from_bank(ResourceType res_type, int amount, Bank &bank);

    void return_resource_card_to_bank(ResourceType res_type, int amount, Bank &bank);
    std::unordered_map<ResourceType,int>& get_PlayerResources();
    void set_PlayerResources(const std::unordered_map<ResourceType,int> &mPlayerResource);

    void increase_num_of_houses();
    void decrease_num_of_houses();
    void increase_num_of_cities();
    void increase_num_of_roads();


    void increase_victory_points();
    void increase_allowed_house_number();
    void decrease_allowed_house_number();
    void decrease_allowed_city_number();
    void decrease_allowed_road_number();
    void decrease_victory_point();

    bool comparePlayers(const Player* pl1, const Player* pl2);

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

    int m_num_of_wood;
    int m_num_of_brick;
    int m_num_of_wool;
    int m_num_of_wheat;
    int m_num_of_stone;

    QColor m_player_color;
    QColor m_city_color;


};

#endif // PLAYER_H
