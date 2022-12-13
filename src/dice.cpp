#include "dice.h"
#include <cstdlib>
#include <time.h>

Dice::Dice():
    m_dice1(0), m_dice2(0) {}

void Dice::set_dice1(int num) { m_dice1 = num; }

void Dice::set_dice2(int num) { m_dice2 = num; }

int Dice::get_dice1() const{ return m_dice1; }

int Dice::get_dice2() const{ return m_dice2; }

int Dice::get_dice_sum() const { return m_dice1 + m_dice2; }

void Dice::roll_dice() {
    srand(time(0));
    set_dice1((rand() % 6) + 1);
    set_dice2((rand() % 6) + 1);
}
