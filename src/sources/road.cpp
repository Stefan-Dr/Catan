#include "../headers/road.h"

//constructor
Road::Road(int owner,int id)
:m_owner(owner),m_id(id){

}
//getters
auto Road::get_id() const -> int{
    return m_id;
}

auto Road::get_can_build() const -> bool
{
    return m_can_build;
}

auto Road::get_owner() const -> int{
    return m_owner;
}

//setters
void Road::set_owner(int owner){
    m_owner = owner;
}

void Road::set_can_build(bool value)
{
    m_can_build = value;
}
