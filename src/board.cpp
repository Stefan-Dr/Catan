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

void Board::addAllNodes(qreal viewWidth, qreal viewHeight){

    //nodes in first row (gornji levi i gornji desni ugao u prvom redu)
    for(int i=0;i<4;i++){
    const auto guiNode = new GUI_Node(new Node(i),QPointF(185+i*130,55));
    addItem(guiNode);
    }
    //nodes in second row(donji levi i donji desni ugao u prvom redu)
    for(int i=4;i<8;i++){
        const auto guiNode = new GUI_Node(new Node(i),QPointF(185+(i-4)*130,130));
        addItem(guiNode);
    }
    //nodes on top (vrhovi heksagona)
    for(int i=8;i<11;i++){
        const auto guiNode = new GUI_Node(new Node(i),QPointF(250+(i-8)*130,20));
        addItem(guiNode);
    }
    //nodes on bottom (dno heksagona) + gornji levi i desni granicnih heksagona
    for(int i=11;i<16;i++){
        const auto guiNode = new GUI_Node(new Node(i),QPointF(120+(i-11)*130,165));
        addItem(guiNode);
    }
    //susedni po y osi za temena opisana gore
    for(int i=16;i<21;i++){
        const auto guiNode = new GUI_Node(new Node(i),QPointF(120+(i-16)*130,240));
        addItem(guiNode);
    }
    //susedni po y osi za temena opisana gore + gornji levi i desni granicnih heksagona
    for(int i=21;i<28;i++){
        const auto guiNode =new GUI_Node(new Node(i),QPointF(57+(i-21)*130,275));
        addItem(guiNode);
    }
    //susedni po y osi za temena opisana gore
    for(int i=28;i<35;i++){
        const auto guiNode =new GUI_Node(new Node(i),QPointF(57+(i-28)*130,345));
        addItem(guiNode);
    }
    //dna gore opisanih heksagona a pocetak donjeg
    for(int i=35;i<40;i++){
        const auto guiNode = new GUI_Node(new Node(i),QPointF(122+(i-35)*130,380));
        addItem(guiNode);
    }
    //susedni po y osi za gore opisane
    for(int i=40;i<45;i++){
        const auto guiNode =new GUI_Node(new Node(i),QPoint(122+(i-40)*130,460));
        addItem(guiNode);
    }
    //dna gore opisanih heksagona a pocetak donjeg
    for(int i=45;i<49;i++){
        const auto guiNode =new GUI_Node(new Node(i),QPointF(187+(i-45)*130,500));
        addItem(guiNode);
    }
    //susedni po y osi za gore opisane
    for(int i=49;i<53;i++){
        const auto guiNode =new GUI_Node(new Node(i),QPointF(187+(i-49)*128,575));
        addItem(guiNode);
    }

    //dno poslednjeg heksagona po y osi
    for(int i=52;i<55;i++){
        const auto guiNode = new GUI_Node(new Node(i),QPointF(250+(i-52)*130,600));
        addItem(guiNode);
    }
}

/*
void Board::SetNodeOnPosition(GUI_Node *node)
{
    const auto boardWidth = static_cast<int>(this->width());

    node->setPos(100,100);
}
*/

