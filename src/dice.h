#ifndef DICE_H
#define DICE_H


class Dice
{
private:
    int m_dice1;
    int m_dice2;
    bool m_button_is_clicked = false;

public:
    Dice();
    Dice(const Dice &) = delete;    //destructor

    void set_button_is_clicked(bool button_clicked);
    void set_dice1(int num);
    void set_dice2(int num);

    int get_dice1() const;
    int get_dice2() const;
    int get_dice_sum() const;
    bool get_button_clicked() const;

    void roll_dice();
};

#endif // DICE_H
