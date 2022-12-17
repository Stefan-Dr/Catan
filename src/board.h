#ifndef BOARD_H
#define BOARD_H
#include <QVector>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>


class Node;
class GUI_Node;
class Field;


class Board : public QGraphicsScene
{

public:
    Board(QObject *parent = nullptr);
    ~Board();
    void addAllNodes();
    void addAllFields();
    QVector<Node *> m_nodes;
    QVector<GUI_Node *> m_gui_nodes;
    QVector<Field *> m_fields;

private:
    const int numOfNodes = 6;


};

#endif // BOARD_H
