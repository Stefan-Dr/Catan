#include "bank.h"
#include <iostream>

using namespace ::std;

// constructor
Bank::Bank()
{
    m_bank_resource[ResourceType::Wood] = 19;   // 19 resources type wood at the start of the game
    m_bank_resource[ResourceType::Brick] = 19;  // 19 resources type brick at the start of the game
    m_bank_resource[ResourceType::Wool] = 19;   // 19 resources type wool at the start of the game
    m_bank_resource[ResourceType::Wheat] = 19;  // 19 resources type wheat at the start of the game
    m_bank_resource[ResourceType::Stone] = 19;  // 19 resources type stone at the start of the game
}

std::unordered_map<ResourceType, unsigned>& Bank::get_bank_resources(){
    return m_bank_resource;
}

// adding num_cards number of resources type res_type to the bank
void Bank::add_resource_card(ResourceType res_type, int num_cards){
    m_bank_resource[res_type] += num_cards;
}

// removing num_cards number of resources type res_type from the bank
void Bank::remove_resource_card(ResourceType res_type, int num_cards) {
    m_bank_resource[res_type] -= num_cards;
}

// printing the content of every single resource in the bank
void Bank::print_bank_content(){
    cout << "Wood : " << m_bank_resource[ResourceType::Wood] << endl;
    cout << "Brick : " << m_bank_resource[ResourceType::Brick] << endl;
    cout << "Wool : " << m_bank_resource[ResourceType::Wool] << endl;
    cout << "Wheat : " << m_bank_resource[ResourceType::Wheat] << endl;
    cout << "Stone : " << m_bank_resource[ResourceType::Stone] << endl;
}
