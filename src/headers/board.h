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

    QVector<Field *> get_fields() ;

    void addAllNodes();
    void addAllFields();
    QVector<Node *> m_nodes;
    QVector<GUI_Node *> m_gui_nodes;
    QVector<Field*> m_fields;
  //  void AddNewRoad(GUI_Road *g_road);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event ) override;
    void setHasTmp(bool x);

    void setCurrColor(QColor color);
    QColor getCurrColor();

    void setRoadColor(QColor color);
    QColor getRoadColor();

    bool m_setHouse = false;
    bool m_setRoad = false;
    bool m_setCity = false;

    bool is_first_turn() const;
    void set_first_turn(bool value);

signals:
    void manageResourcesHouse();
    void manageResourcesRoad();
    void manageResourcesCity();
    void invalidHouse();
    void invalidRoad();
    void invalidCity();

public slots:
    void Redraw();
    void setHouse(bool x);


private:
    const int numOfNodes = 6;
    bool m_hasTmp = false;
    GUI_Node* m_tmp;
    QColor m_curr_color;
    QColor m_road_color;
    bool m_first_turn = true;

};

#endif // BOARD_H
