#ifndef BANK_H
#define BANK_H

#include "resourcetype.h"
#include <unordered_map>

class Bank
{
public:
  // constructor
  Bank();
  // can not have copy of bank
  Bank(const Bank&) = delete;

  std::unordered_map<ResourceType, unsigned>& get_bank_resources();

  // getters
  unsigned get_num_of_brick_from_bank() const;
  unsigned get_num_of_wood_from_bank() const;
  unsigned get_num_of_wool_from_bank() const;
  unsigned get_num_of_wheat_from_bank() const;
  unsigned get_num_of_stone_from_bank() const;

  void print_bank_content();
  void add_resource_card(ResourceType, int num_cards);
  void remove_resource_card(ResourceType, int num_card);

private:
  std::unordered_map<ResourceType, unsigned> m_bank_resource;
  unsigned m_num_of_brick;
  unsigned m_num_of_wood;
  unsigned m_num_of_wool;
  unsigned m_num_of_wheat;
  unsigned m_num_of_stone;
};

#endif // BANK_H
