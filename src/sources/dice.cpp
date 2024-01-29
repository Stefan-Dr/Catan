#include "../headers/dice.h"

#include <time.h>

#include <cstdlib>

// constructor
Dice::Dice() : m_dice1(0), m_dice2(0) {}

// setters
void Dice::set_button_is_clicked(bool button_clicked) {
  m_button_is_clicked = button_clicked;
}

void Dice::set_dice_is_rolled(bool x) { m_dice_is_rolled = x; }

void Dice::set_dice1(int num) { m_dice1 = num; }

void Dice::set_dice2(int num) { m_dice2 = num; }

// getters
int Dice::get_dice1() const { return m_dice1; }

int Dice::get_dice2() const { return m_dice2; }

int Dice::get_dice_sum() const { return m_dice1 + m_dice2; }

bool Dice::get_button_clicked() const { return m_button_is_clicked; }

bool Dice::get_dice_is_rolled() const { return m_dice_is_rolled; }

void Dice::roll_dice() {
  srand(time(0));
  set_dice1((rand() % 6) + 1);
  set_dice2((rand() % 6) + 1);
}
