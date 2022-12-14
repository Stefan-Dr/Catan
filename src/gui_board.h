#ifndef GUI_BOARD_H
#define GUI_BOARD_H

#include "board.h"
#include "gui_node.h"
#include <QObject>
#include <QPointF>
#include <QVector>

class GUI_Board : public Board
{
public:
    GUI_Board(QObject *parent = nullptr);
    void addAllNodes(qreal viewWidth, qreal viewHeight);

private:
    const int numOfNodes = 54;

};

#endif // GUI_BOARD_H
