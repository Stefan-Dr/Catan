#ifndef MAP_H
#define MAP_H

#include "bank.h"
#include "node.h"
#include "player.h"
//#include "road.h"

#include <iostream>
#include <map>
#include <set>
#include <vector>

class Map
{
private:

    struct Neighbour {
       Node *node;
       Road *road;
       //konstruktor
       Neighbour(Node *node, Road *road)
           : node(node), road(road) {}
       //destruktor
       Neighbour(const Neighbour &) = delete;
     };

    //broj cvorova
    int m_number_of_nodes;
    //vektor puteva
    std::vector<Road *> m_roads;
    //vektor heksagona
    std::vector<Fields *> m_fields;
    //vektor cvorova
    std::vector<Node *> m_nodes;
    //lisa susedstva
    std::vector<std::vector<Neighbour *>> m_adjacency_list;


public:
    //konstruktor
    Map(const std::vector<int> &numbers_for_fields,
        const std::vector<ResourceType> &types_for_fields);
    //destruktor
    ~Map();
    //geteri
    int get_number_of_nodes() const;
    const std::vector<Road *> &get_roads() const;
    const std::vector<Fields *> &get_fields() const;
    const std::vector<Node *> &get_nodes() const;
    const std::vector<std::vector<Neighbour *>> &get_adjacency_list() const;

};

#endif // MAP_H
