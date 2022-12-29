#include <catch.hpp>

#include "../../06-catan/src/node.h"


TEST_CASE("NODE")
{

SECTION("01: Node::get_id "){

    //ARRANGE

    const int expected = 1;

    //ACT
    int id = 1;
    Node* node = new Node(id);
    int result = node->get_id();


    //ASSERT
    REQUIRE(expected == result);
}

SECTION("02: Node::get_can_build with set"){

    //ARRANGE

    const bool expected = true;

    //ACT
    int id = 1;
    Node* node = new Node(id);
    node->set_can_build(true);
    bool result = node->get_can_build();
    //ASSERT
    REQUIRE(expected == result);
}
SECTION("03: Node::get_is_house_build"){

    //ARRANGE

    const bool expected = false;

    //ACT
    int id = 1;
    Node* node = new Node(id);

    bool result = node->get_is_house_built();
    //ASSERT
    REQUIRE(expected == result);
}
SECTION("03: Node::get_is_city_build"){

    //ARRANGE

    const bool expected = false;

    //ACT
    int id = 1;
    Node* node = new Node(id);

    bool result = node->get_is_city_built();
    //ASSERT
    REQUIRE(expected == result);
}

SECTION("04: Node::get_can_build without set"){

    //ARRANGE

    const bool expected = false;

    //ACT
    int id = 1;
    Node* node = new Node(id);

    bool result = node->get_can_build();
    //ASSERT
    REQUIRE(expected == result);
}

SECTION("05: Node:: get_neighbours "){

    //ARRANGE
    const QVector<int> expected = {2,6};


    //ACT
    int id = 1;
    const auto node1 = new Node(id);
    QVector<int> node1_neighbours = {2,6};
    node1->set_all_neighbours(node1_neighbours);
    QVector<int> result = node1->get_neighbours();
    //ASSERT
    REQUIRE(expected == result);
}


}
