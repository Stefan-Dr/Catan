#include <catch.hpp>

#include "../../06-catan/src/headers/road.h"


TEST_CASE("ROAD")
{
SECTION("01: Road::get_owner without set"){

    //ARRANGE

    const int expected = 1;

    //ACT
    int owner = 1;
    int id = 1;
    Road* road = new Road(owner, id);
    //road->set_owner(1)
    int result = road->get_owner();

    //ASSERT
    REQUIRE(expected == result);
}
SECTION("02: Road::get_owner with set"){

    //ARRANGE

    const int expected = 2;

    //ACT
    int owner;
    int id = 2;
    Road* road = new Road(owner, id);
    road->set_owner(2);
    int result = road->get_owner();

    //ASSERT
    REQUIRE(expected == result);
}
SECTION("03: Road::get_can_build"){

    //ARRANGE

    const bool expected = true;

    //ACT
    int owner = 2;
    int id = 2;
    Road* road = new Road(owner, id);
    road->set_can_build(true);
    bool result = road->get_can_build();

    //ASSERT
    REQUIRE(expected == result);
}

}
