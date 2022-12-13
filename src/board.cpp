#include "board.h"
#include "node.h"
#include "gui_node.h"

Board::Board(QObject *parent)
    : QGraphicsScene(parent)
{

}

void Board::SetNodeOnPosition(GUI_Node *node)
{
    const auto boardWidth = static_cast<int>(this->width());

    node->setPos(100,100);
}
