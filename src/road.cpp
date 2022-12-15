#include "road.h"

Road::Road(int owner,int id)
:m_owner(owner),m_id(id){

}

int Road::get_id() const{
    return m_id;
}

int Road::get_owner() const{
    return m_owner;
}

void Road::set_owner(int owner){
    m_owner = owner;
}
