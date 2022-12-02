#include "node.h"

//constructor
Node::Node(int m_id)
    : m_id(m_id), m_is_house_built(false), m_is_city_built(false),
      m_owner(0), m_can_build(false) {}

int Node::get_id() const { return m_id; }

bool Node::get_is_house_built() const { return m_is_house_built; }

bool Node::get_is_city_built() const { return m_is_city_built; }

bool Node::get_can_build() const { return m_can_build; }

int Node::get_owner() const { return m_owner; }

void Node::set_is_house_built(bool value) { m_is_house_built = value; }

void Node::set_is_city_built(bool value) { m_is_city_built = value; }

void Node::set_can_build(bool value) { m_can_build = value; }

void Node::set_owner(int owner) { m_owner = owner; }

void Node::place_house(int owner) {
    set_is_house_built(true);
    set_owner(owner);
}

void Node::place_city(int owner) {
    set_is_house_built(false);
    set_is_city_built(true);
    set_owner(owner);
}


