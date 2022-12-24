#ifndef BOARD_H
#define BOARD_H
#include <QVector>
#include <QPointF>
#include <QObject>
#include <QGraphicsScene>

#include<QGraphicsSceneMouseEvent>
#include<QGraphicsLineItem>
#include "gui_road.h"
class Node;
class GUI_Node;
class GUI_Road;
class Field;

class Board : public QGraphicsScene
{
Q_OBJECT
public:
    Board(QObject *parent = nullptr);
    ~Board();
    void addAllNodes();
    void addAllFields();
    QVector<Node *> m_nodes;
    QVector<GUI_Node *> m_gui_nodes;
    QVector<Field*> m_fields;
  //  void AddNewRoad(GUI_Road *g_road);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event ) override;
    void setHasTmp(bool x);

public slots:
    void Redraw();

private:
    const int numOfNodes = 6;
    bool m_hasTmp = false;
    GUI_Node* m_tmp;

};

#endif // BOARD_H
