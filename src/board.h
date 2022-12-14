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
    virtual void addAllNodes(qreal viewWidth,qreal viewHeight) = 0;
    QVector<Node *> m_nodes;

};

#endif // BOARD_H
