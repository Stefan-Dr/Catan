#include "../headers/dice.h"
#include <cstdlib>
#include <ctime>

//constructor
Dice::Dice():
    m_dice1(0), m_dice2(0) {}

//setters
void Dice::set_button_is_clicked(bool button_clicked){
    m_button_is_clicked = button_clicked;
}

void Dice::set_dice_is_rolled(bool x) {
    m_dice_is_rolled = x;
}

void Dice::set_dice1(int num) {
    m_dice1 = num;
}

void Dice::set_dice2(int num) {
    m_dice2 = num;
}

//getters
auto Dice::get_dice1() const -> int{
    return m_dice1;
}

auto Dice::get_dice2() const -> int{
    return m_dice2;
}

auto Dice::get_dice_sum() const -> int {
    return m_dice1 + m_dice2;
}

auto Dice::get_button_clicked() const -> bool {
    return m_button_is_clicked;
}

auto Dice::get_dice_is_rolled()const -> bool {
    return m_dice_is_rolled;
}

void Dice::roll_dice() {
    srand(time(nullptr));
    set_dice1((rand() % 6) + 1);
    set_dice2((rand() % 6) + 1);
}
