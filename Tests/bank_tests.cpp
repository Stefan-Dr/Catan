#include <catch.hpp>

#include "../../06-catan/src/bank.h"

TEST_CASE("BANK")
{

SECTION("1:Bank::get_num_of_brick_from_bank "){

    //ARRANGE

    const int expected = 19;

    //ACT
    Bank* bank = new Bank();
    int result = bank->get_num_of_brick_from_bank();
    //ASSERT
    REQUIRE(expected == result);
}

SECTION("2:Bank::get_num_of_wood_from_bank "){

    //ARRANGE

    const int expected = 19;

    //ACT
    Bank* bank = new Bank();
    int result = bank->get_num_of_wood_from_bank();
    //ASSERT
    REQUIRE(expected == result);
}
SECTION("3:Bank::get_num_of_wool_from_bank"){

    //ARRANGE

    const int expected = 19;

    //ACT
    Bank* bank = new Bank();
    int result = bank->get_num_of_wool_from_bank();
    //ASSERT
    REQUIRE(expected == result);
}

SECTION("4:Bank::get_num_of_wheat_from_bank"){

    //ARRANGE

    const int expected = 19;

    //ACT
    Bank* bank = new Bank();
    int result = bank->get_num_of_wheat_from_bank();
    //ASSERT
    REQUIRE(expected == result);
}

SECTION("5:Bank::get_num_of_stone_from_bank "){

    //ARRANGE

    const int expected = 19;

    //ACT
    Bank* bank = new Bank();
    int result = bank->get_num_of_stone_from_bank();
    //ASSERT
    REQUIRE(expected == result);
}
SECTION("6:Bank::bank_resource"){

    //ARRANGE

    const int expected = 0;

    //ACT
    Bank* bank = new Bank();
    std::unordered_map<ResourceType, unsigned> bank_resource;

    //unsigned result = bank_resource.
    int result = bank_resource.size();

    //ASSERT
    REQUIRE(expected == result);
}

SECTION("7:Bank::add_resource_card"){

    //ARRANGE

    const int expected = 21;

    //ACT
    Bank* bank = new Bank();
    std::unordered_map<ResourceType, unsigned> bank_resource;
    bank->add_resource_card(ResourceType::Brick, 2);
    unsigned result = bank->get_num_of_brick_from_bank();


    //ASSERT
    REQUIRE(expected == result);
}

SECTION("7:Bank::remove_resource_card"){

    //ARRANGE

    const int expected = 17;

    //ACT
    Bank* bank = new Bank();
    std::unordered_map<ResourceType, unsigned> bank_resource;
    bank->remove_resource_card(ResourceType::Brick, 2);
    unsigned result = bank->get_num_of_brick_from_bank();


    //ASSERT
    REQUIRE(expected == result);
}
}
