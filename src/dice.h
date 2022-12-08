#ifndef DICE_H
#define DICE_H


class Dice
{
private:
    int m_dice1;
    int m_dice2;
public:
    Dice();
    Dice(const Dice &) = delete;    //destructor

    void set_dice1(int num);
    void set_dice2(int num);
    int get_dice1() const;
    int get_dice2() const;
    int get_dice_sum() const;
    void roll_dice();
};

#endif // DICE_H
