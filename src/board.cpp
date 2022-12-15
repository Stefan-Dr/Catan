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

void Board::addAllNodes(){

    /*prvi heksagon prvi red */

    //gornji levi ugao prvog heksagona njegovi susedi su - prvi ispod njega po y osi (185,130) i vrh heksagona (250,20)
    const auto node1 = new Node(1);
    m_nodes.push_back(node1);
    m_gui_nodes.push_back(new GUI_Node(node1,QPointF(185,55)));

    //vrh prvog heksagona njegovi susedi su - (185,130),(315,55)
    const auto node2 = new Node(2);
    m_nodes.push_back(node2);
    m_gui_nodes.push_back(new GUI_Node(node2,QPointF(250,20)));

    //gornji desni prvog heksagona, susedi su (250,20),(315,130),(380,20)
    const auto node3 = new Node(3);
    m_nodes.push_back(node3);
    m_gui_nodes.push_back(new GUI_Node(node3,QPointF(315,55)));

    //donji desni prvog heksagona, susedi su (315,55),(250,165),(380,165)
    const auto node4 = new Node(4);
    m_nodes.push_back(node4);
    m_gui_nodes.push_back(new GUI_Node(node4,QPointF(315,130)));

    //dno prvog heksagona, susedi su (315,130),(185,130),(250,240)
    const auto node5 = new Node(5);
    m_nodes.push_back(node5);
    m_gui_nodes.push_back(new GUI_Node(node5,QPointF(250,165)));


    //donji levi prvog heksagona susedi su (185,55),(250,165)
    const auto node6 = new Node(6);
    m_nodes.push_back(node6);
    m_gui_nodes.push_back(new GUI_Node(node6,QPointF(185,130)));

    /*DRUGI HEKSAGON PRVI RED*/

    //vrh drugog heksagona susedi su (315,15),(445,55)
    const auto node7 = new Node(7);
    m_nodes.push_back(node7);
    m_gui_nodes.push_back(new GUI_Node(node7,QPointF(380,20)));

    //gornji desni ugao heksagona susedi su (510,20),(445,130)
    const auto node8 = new Node(8);
    m_nodes.push_back(node8);
    m_gui_nodes.push_back(new GUI_Node(node8,QPointF(445,55)));

    //donji desni heksagona, susedi su (445,55),(250,165),(380,165)
    const auto node9 = new Node(9);
    m_nodes.push_back(node9);
    m_gui_nodes.push_back(new GUI_Node(node9,QPointF(445,130)));

    //dno heksagona susedi (215,130),(340,130),(380,240)
    const auto node10 = new Node(10);
    m_nodes.push_back(node10);
    m_gui_nodes.push_back(new GUI_Node(node10,QPointF(380,165)));

    //treci heksagon

    //vrh treceg heksagona prvi red
    const auto node11 = new Node(11);
    m_nodes.push_back(node11);
    m_gui_nodes.push_back(new GUI_Node(node11,QPointF(510,20)));

    //gornji desni treceg heksagona treceg
    const auto node12 = new Node(12);
    m_nodes.push_back(node12);
    m_gui_nodes.push_back(new GUI_Node(node12,QPointF(575,55)));

    //donji desni treceg heksagona treceg
    const auto node13 = new Node(13);
    m_nodes.push_back(node13);
    m_gui_nodes.push_back(new GUI_Node(node13,QPointF(575,130)));

    //dno treceg heksagona prvi red
    const auto node14 = new Node(14);
    m_nodes.push_back(node14);
    m_gui_nodes.push_back(new GUI_Node(node14,QPointF(510,165)));


    //drugi red

    //gornji levi u prvom heksagonu
    const auto node15 = new Node(15);
    m_nodes.push_back(node15);
    m_gui_nodes.push_back(new GUI_Node(node15,QPointF(120,165)));

    //donji levi u prvom heksagonu
    const auto node16 = new Node(16);
    m_nodes.push_back(node16);
    m_gui_nodes.push_back(new GUI_Node(node16,QPointF(120,240)));


    //dno prvog heksagona

    const auto node17 = new Node(17);
    m_nodes.push_back(node17);
    m_gui_nodes.push_back(new GUI_Node(node17,QPointF(185,270)));

    //donji desni prvog heksagona

    const auto node18 = new Node(18);
    m_nodes.push_back(node18);
    m_gui_nodes.push_back(new GUI_Node(node18,QPointF(250,240)));


    //drugi heksagon drugi red

    //dno heksagona

    const auto node19 = new Node(19);
    m_nodes.push_back(node19);
    m_gui_nodes.push_back(new GUI_Node(node8,QPointF(315,270)));

    //donji desni drugog

    const auto node20 = new Node(20);
    m_nodes.push_back(node20);
    m_gui_nodes.push_back(new GUI_Node(node20,QPointF(380,240)));


    //treci

    //dno treceg

    const auto node21 = new Node(21);
    m_nodes.push_back(node21);
    m_gui_nodes.push_back(new GUI_Node(node21,QPointF(445,270)));

    //donji desni treceg

    const auto node22 = new Node(22);
    m_nodes.push_back(node22);
    m_gui_nodes.push_back(new GUI_Node(node22,QPointF(510,240)));

    //cetvrti

    //dno cetvrtog


    const auto node23 = new Node(23);
    m_nodes.push_back(node23);
    m_gui_nodes.push_back(new GUI_Node(node23,QPointF(575,270)));

    //gornji desni cetvrtog
    const auto node24 = new Node(24);
    m_nodes.push_back(node24);
    m_gui_nodes.push_back(new GUI_Node(node24,QPointF(640,165)));

    //donji desni cetvrtog

    const auto node25 = new Node(25);
    m_nodes.push_back(node25);
    m_gui_nodes.push_back(new GUI_Node(node25,QPointF(640,240)));


    //TRECI RED

    //gornji levi prvog

    const auto node26 = new Node(26);
    m_nodes.push_back(node26);
    m_gui_nodes.push_back(new GUI_Node(node26,QPointF(57,275)));

    //donji levi prvog

    const auto node27 = new Node(27);
    m_nodes.push_back(node27);
    m_gui_nodes.push_back(new GUI_Node(node27,QPointF(57,350)));

    //dno prvog

    const auto node28 = new Node(28);
    m_nodes.push_back(node28);
    m_gui_nodes.push_back(new GUI_Node(node28,QPointF(122,380)));

    //donji desni prvog

    const auto node29 = new Node(29);
    m_nodes.push_back(node29);
    m_gui_nodes.push_back(new GUI_Node(node29,QPointF(187,350)));


    //donji drugog

    const auto node30 = new Node(30);
    m_nodes.push_back(node30);
    m_gui_nodes.push_back(new GUI_Node(node30,QPointF(252,380)));

    //donji desni drugog

    const auto node31 = new Node(31);
    m_nodes.push_back(node31);
    m_gui_nodes.push_back(new GUI_Node(node31,QPointF(317,350)));

    //donji treceg

    const auto node32 = new Node(32);
    m_nodes.push_back(node32);
    m_gui_nodes.push_back(new GUI_Node(node32,QPointF(382,380)));

    //donji desni treceg

    const auto node33 = new Node(33);
    m_nodes.push_back(node33);
    m_gui_nodes.push_back(new GUI_Node(node33,QPointF(447,350)));


    //donji cetvrtog

    const auto node34 = new Node(34);
    m_nodes.push_back(node34);
    m_gui_nodes.push_back(new GUI_Node(node34,QPointF(512,380)));

    //donji desni cetvrtog

    const auto node35 = new Node(35);
    m_nodes.push_back(node35);
    m_gui_nodes.push_back(new GUI_Node(node35,QPointF(577,350)));

    //donji petog

    const auto node36 = new Node(36);
    m_nodes.push_back(node36);
    m_gui_nodes.push_back(new GUI_Node(node36,QPointF(642,380)));

    //donji desni petog

    const auto node37 = new Node(37);
    m_nodes.push_back(node37);
    m_gui_nodes.push_back(new GUI_Node(node37,QPointF(707,350)));

    //gornji desni petog

    const auto node38 = new Node(38);
    m_nodes.push_back(node38);
    m_gui_nodes.push_back(new GUI_Node(node38,QPointF(707,275)));

    //CETVRTI RED

    //donji levi prvog

    const auto node39 = new Node(39);
    m_nodes.push_back(node39);
    m_gui_nodes.push_back(new GUI_Node(node39,QPointF(122,460)));


    //dno prvog

    const auto node40 = new Node(40);
    m_nodes.push_back(node40);
    m_gui_nodes.push_back(new GUI_Node(node40,QPointF(187,500)));

    //donji desni prvog

    const auto node41 = new Node(41);
    m_nodes.push_back(node41);
    m_gui_nodes.push_back(new GUI_Node(node41,QPointF(252,460)));


    //dno drugog

    const auto node42 = new Node(42);
    m_nodes.push_back(node42);
    m_gui_nodes.push_back(new GUI_Node(node42,QPointF(317,500)));

    //donji desni prvog

    const auto node43 = new Node(43);
    m_nodes.push_back(node43);
    m_gui_nodes.push_back(new GUI_Node(node43,QPointF(382,460)));


    //dno treceg

    const auto node44 = new Node(44);
    m_nodes.push_back(node44);
    m_gui_nodes.push_back(new GUI_Node(node44,QPointF(447,500)));

    //donji desni treceg

    const auto node45 = new Node(45);
    m_nodes.push_back(node45);
    m_gui_nodes.push_back(new GUI_Node(node45,QPointF(512,460)));


    //dno cetvrtog

    const auto node46 = new Node(46);
    m_nodes.push_back(node46);
    m_gui_nodes.push_back(new GUI_Node(node46,QPointF(577,500)));

    //donji desni prvog

    const auto node47 = new Node(47);
    m_nodes.push_back(node47);
    m_gui_nodes.push_back(new GUI_Node(node47,QPointF(642,460)));


    //peti red

    //donji levi prvog

    const auto node48 = new Node(48);
    m_nodes.push_back(node48);
    m_gui_nodes.push_back(new GUI_Node(node48,QPointF(187,575)));

    //dno prvog

    const auto node49 = new Node(49);
    m_nodes.push_back(node49);
    m_gui_nodes.push_back(new GUI_Node(node49,QPointF(250,600)));

    //donji desni prvog
    const auto node50 = new Node(50);
    m_nodes.push_back(node50);
    m_gui_nodes.push_back(new GUI_Node(node50,QPointF(317,575)));



    //dno drugog

    const auto node51= new Node(51);
    m_nodes.push_back(node51);
    m_gui_nodes.push_back(new GUI_Node(node51,QPointF(380,600)));

    //donji desni prvog
    const auto node52 = new Node(52);
    m_nodes.push_back(node52);
    m_gui_nodes.push_back(new GUI_Node(node52,QPointF(444,575)));


    //dno treceg

    const auto node53= new Node(53);
    m_nodes.push_back(node53);
    m_gui_nodes.push_back(new GUI_Node(node53,QPointF(510,600)));

    //donji desni treceg
    const auto node54 = new Node(54);
    m_nodes.push_back(node54);
    m_gui_nodes.push_back(new GUI_Node(node54,QPointF(575,575)));


    for(int i=0;i<54;i++)
          addItem(m_gui_nodes[i]);

}

/*
void Board::SetNodeOnPosition(GUI_Node *node)
{
    const auto boardWidth = static_cast<int>(this->width());

    node->setPos(100,100);
}
*/

