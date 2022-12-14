#include "board.h"
#include "node.h"
#include "gui_node.h"

Board::Board(QObject *parent): QGraphicsScene(parent){}

Board::~Board(){
    for(auto node : m_nodes){
        delete node;
    }
    m_nodes.clear();
}


/*
void Board::SetNodeOnPosition(GUI_Node *node)
{
    const auto boardWidth = static_cast<int>(this->width());

    node->setPos(100,100);
}
*/

