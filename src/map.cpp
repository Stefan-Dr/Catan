#include <iostream>

#include "map.h"


//konstruktor
Map::Map(const std::vector<int> &numbers_for_fields,
         const std::vector<ResourceType> &types_for_fields) {
    m_number_of_nodes = 54;
    m_adjacency_list.resize(m_number_of_nodes);
    m_nodes.resize(m_number_of_nodes);
    for (auto i = 0u; i < m_number_of_nodes; i++) {
        m_nodes[i] = new Node(i); // static cast ? explicit ?
    }
}
//destruktor
Map::~Map() {
    for (const auto &node : m_nodes) {
        delete node;
    }
    for (const auto &road : m_roads) {
        delete road;
    }
    for (const auto &neighbours : m_adjacency_list) {
        for (const auto &neighbour : neighbours) {
            delete neighbour;
        }
    }
    for (const auto &fields : m_fields) {
        delete fields;
    }
}

//geteri

int Map::get_number_of_nodes() const {
    return m_number_of_nodes;
}

const std::vector<Road *> &Map::get_roads() const {
    return m_roads;
}

const std::vector<Fields *> &Map::get_fields() const {
    return m_fields;
}

const std::vector<Node *> &Map::get_nodes() const {
    return m_nodes;
}

const std::vector<std::vector<Map::Neighbour *>> & Map::get_adjacency_list() const {
    return m_adjacency_list;
}








