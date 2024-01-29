#ifndef DICE_H
#define DICE_H

class Dice {
 private:
  int m_dice1;
  int m_dice2;
  bool m_button_is_clicked = false;
  bool m_dice_is_rolled;

 public:
  // constructor
  Dice();
  // destructor
  Dice(const Dice &) = delete;

  // setters
  void set_button_is_clicked(bool button_clicked);
  void set_dice1(int num);
  void set_dice2(int num);
  void set_dice_is_rolled(bool x);

  // getters
  int get_dice1() const;
  int get_dice2() const;
  int get_dice_sum() const;
  bool get_button_clicked() const;
  bool get_dice_is_rolled() const;

  void roll_dice();
};

#endif  // DICE_H
