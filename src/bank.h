#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include "resourcetype.h"

class Bank
{
public:
    Bank(); // constructor
    Bank(const Bank &) = delete;    //destructor

    void print_bank_content();
    void add_resource_card(ResourceType, int num_cards);
    void remove_resource_card(ResourceType, int num_card);

private:
    std::unordered_map<ResourceType, unsigned> m_bank_resource;
};

#endif // BANK_H
