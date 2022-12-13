#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>

class Node;
class GUI_Node;


class Board : public QGraphicsScene
{
public:
    explicit Board(QObject *parent = nullptr);

private:
    void SetNodeOnPosition(GUI_Node *node);
};

#endif // BOARD_H
