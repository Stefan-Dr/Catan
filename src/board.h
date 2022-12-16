#ifndef BOARD_H
#define BOARD_H
#include <QVector>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

class Node;
class GUI_Node;


class Board : public QGraphicsScene
{

public:
    Board(QObject *parent = nullptr);
    ~Board();
    void addAllNodes();
    QVector<Node *> m_nodes;
    QVector<GUI_Node *> m_gui_nodes;

private:
    const int numOfNodes = 6;


};

#endif // BOARD_H
