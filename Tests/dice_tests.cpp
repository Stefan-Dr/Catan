#include <catch.hpp>

#include "../../06-catan/src/dice.h"


TEST_CASE("DICE")
{
    SECTION("01: Dice::delete"){

           //ACT
           Dice* dice= new Dice();
           delete dice;

           //Assert
           REQUIRE_NOTHROW(dice);


       }
    SECTION("02: Dice::get_dice1 "){

        //ARRANGE

        const int expected = 1;

        //ACT
        Dice* dice1= new Dice();
        dice1->set_dice1(1);
        int result = dice1->get_dice1();

        //ASSERT
        REQUIRE(expected == result);
    }
    SECTION("03: Dice::get_dice2"){

        //ARRANGE

        const int expected = 5;

        //ACT
        Dice* dice2= new Dice();
        dice2->set_dice2(5);
        int result = dice2->get_dice2();

        //ASSERT
        REQUIRE(expected == result);
    }


}
