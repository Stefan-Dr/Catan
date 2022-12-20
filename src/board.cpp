#include "board.h"
#include "field.h"
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
    //dodavanje suseda za node1
    QVector<int> node1_neighbours = {2,6};
    node1->set_all_neighbours(node1_neighbours);


    //vrh prvog heksagona njegovi susedi su - (185,130),(315,55)
    const auto node2 = new Node(2);
    m_nodes.push_back(node2);
    m_gui_nodes.push_back(new GUI_Node(node2,QPointF(250,20)));
    //dodavanje suseda za node2
    QVector<int> node2_neighbours = {1,3};
    node2->set_all_neighbours(node2_neighbours);

    //gornji desni prvog heksagona, susedi su (250,20),(315,130),(380,20)
    const auto node3 = new Node(3);
    m_nodes.push_back(node3);
    m_gui_nodes.push_back(new GUI_Node(node3,QPointF(315,55)));
    //dodavanje suseda za node3
    QVector<int> node3_neighbours = {2,4,7};
    node3->set_all_neighbours(node3_neighbours);

    //donji desni prvog heksagona, susedi su (315,55),(250,165),(380,165)
    const auto node4 = new Node(4);
    m_nodes.push_back(node4);
    m_gui_nodes.push_back(new GUI_Node(node4,QPointF(315,130)));
    //dodavanje suseda za node4
    QVector<int> node4_neighbours = {3,5,10};
    node4->set_all_neighbours(node4_neighbours);

    //dno prvog heksagona, susedi su (315,130),(185,130),(250,240)
    const auto node5 = new Node(5);
    m_nodes.push_back(node5);
    m_gui_nodes.push_back(new GUI_Node(node5,QPointF(250,165)));
    //dodavanje suseda za node5
    QVector<int> node5_neighbours = {4,6,18};
    node5->set_all_neighbours(node5_neighbours);


    //donji levi prvog heksagona susedi su (185,55),(250,165)
    const auto node6 = new Node(6);
    m_nodes.push_back(node6);
    m_gui_nodes.push_back(new GUI_Node(node6,QPointF(185,130)));
    //dodavanje suseda za node6
    QVector<int> node6_neighbours = {1,5,15};
    node6->set_all_neighbours(node6_neighbours);

    /*DRUGI HEKSAGON PRVI RED*/

    //vrh drugog heksagona susedi su (315,15),(445,55)
    const auto node7 = new Node(7);
    m_nodes.push_back(node7);
    m_gui_nodes.push_back(new GUI_Node(node7,QPointF(380,20)));
    //dodavanje suseda za node7
    QVector<int> node7_neighbours = {3,8};
    node7->set_all_neighbours(node7_neighbours);

    //gornji desni ugao heksagona susedi su (510,20),(445,130)
    const auto node8 = new Node(8);
    m_nodes.push_back(node8);
    m_gui_nodes.push_back(new GUI_Node(node8,QPointF(445,55)));
    //dodavanje suseda za node 8
    QVector<int> node8_neighbours = {7,9,11};
    node8->set_all_neighbours(node8_neighbours);

    //donji desni heksagona, susedi su (445,55),(250,165),(380,165)
    const auto node9 = new Node(9);
    m_nodes.push_back(node9);
    m_gui_nodes.push_back(new GUI_Node(node9,QPointF(445,130)));
    //dodavanje suseda za node9
    QVector<int> node9_neighbours = {8,10,14};
    node9->set_all_neighbours(node9_neighbours);

    //dno heksagona susedi (215,130),(340,130),(380,240)
    const auto node10 = new Node(10);
    m_nodes.push_back(node10);
    m_gui_nodes.push_back(new GUI_Node(node10,QPointF(380,165)));
    //dodavanje suseda za node10
    QVector<int> node10_neighbours = {4,9,20};
    node10->set_all_neighbours(node10_neighbours);
    //treci heksagon

    //vrh treceg heksagona prvi red
    const auto node11 = new Node(11);
    m_nodes.push_back(node11);
    m_gui_nodes.push_back(new GUI_Node(node11,QPointF(510,20)));
    //dodavanje suseda za node11
    QVector<int> node11_neighbours = {8,12};
    node11->set_all_neighbours(node11_neighbours);

    //gornji desni treceg heksagona treceg
    const auto node12 = new Node(12);
    m_nodes.push_back(node12);
    m_gui_nodes.push_back(new GUI_Node(node12,QPointF(575,55)));
    //dodavanje suseda za node12
    QVector<int> node12_neighbours = {11,13};
    node12->set_all_neighbours(node12_neighbours);

    //donji desni treceg heksagona treceg
    const auto node13 = new Node(13);
    m_nodes.push_back(node13);
    m_gui_nodes.push_back(new GUI_Node(node13,QPointF(575,130)));
    //dodavanje suseda za node13
    QVector<int> node13_neighbours = {12,14,24};
    node13->set_all_neighbours(node13_neighbours);

    //dno treceg heksagona prvi red
    const auto node14 = new Node(14);
    m_nodes.push_back(node14);
    m_gui_nodes.push_back(new GUI_Node(node14,QPointF(510,165)));
    //dodavanje suseda za node14
    QVector<int> node14_neighbours = {9,13,22};
    node14->set_all_neighbours(node14_neighbours);

    //drugi red

    //gornji levi u prvom heksagonu
    const auto node15 = new Node(15);
    m_nodes.push_back(node15);
    m_gui_nodes.push_back(new GUI_Node(node15,QPointF(120,165)));
    //dodavanje suseda za node15
    QVector<int> node15_neighbours = {6,16};
    node15->set_all_neighbours(node15_neighbours);

    //donji levi u prvom heksagonu
    const auto node16 = new Node(16);
    m_nodes.push_back(node16);
    m_gui_nodes.push_back(new GUI_Node(node16,QPointF(120,240)));
    //dodavanje suseda za node16
    QVector<int> node16_neighbours = {15,17,26};
    node16->set_all_neighbours(node16_neighbours);


    //dno prvog heksagona

    const auto node17 = new Node(17);
    m_nodes.push_back(node17);
    m_gui_nodes.push_back(new GUI_Node(node17,QPointF(185,270)));
    //dodavanje suseda za node17
    QVector<int> node17_neighbours = {16,18,29};
    node17->set_all_neighbours(node17_neighbours);

    //donji desni prvog heksagona

    const auto node18 = new Node(18);
    m_nodes.push_back(node18);
    m_gui_nodes.push_back(new GUI_Node(node18,QPointF(250,240)));
    //dodavanje suseda za node18
    QVector<int> node18_neighbours = {5,17,19};
    node18->set_all_neighbours(node18_neighbours);


    //drugi heksagon drugi red

    //dno heksagona

    const auto node19 = new Node(19);
    m_nodes.push_back(node19);
    m_gui_nodes.push_back(new GUI_Node(node8,QPointF(315,270)));
    //dodavanje suseda za node19
    QVector<int> node19_neighbours = {18,20,31};
    node19->set_all_neighbours(node19_neighbours);

    //donji desni drugog

    const auto node20 = new Node(20);
    m_nodes.push_back(node20);
    m_gui_nodes.push_back(new GUI_Node(node20,QPointF(380,240)));
    //dodavanje suseda za node20
    QVector<int> node20_neighbours = {10,19,21};
    node20->set_all_neighbours(node20_neighbours);


    //treci

    //dno treceg

    const auto node21 = new Node(21);
    m_nodes.push_back(node21);
    m_gui_nodes.push_back(new GUI_Node(node21,QPointF(445,270)));
    //dodavanje suseda za node21
    QVector<int> node21_neighbours = {20,22,33};
    node21->set_all_neighbours(node21_neighbours);

    //donji desni treceg

    const auto node22 = new Node(22);
    m_nodes.push_back(node22);
    m_gui_nodes.push_back(new GUI_Node(node22,QPointF(510,240)));
    //dodavanje suseda za node22
    QVector<int> node22_neighbours = {14,21,23};
    node22->set_all_neighbours(node22_neighbours);
    //cetvrti

    //dno cetvrtog


    const auto node23 = new Node(23);
    m_nodes.push_back(node23);
    m_gui_nodes.push_back(new GUI_Node(node23,QPointF(575,270)));
    //dodavanje suseda za node23
    QVector<int> node23_neighbours = {22,25,35};
    node23->set_all_neighbours(node23_neighbours);

    //gornji desni cetvrtog
    const auto node24 = new Node(24);
    m_nodes.push_back(node24);
    m_gui_nodes.push_back(new GUI_Node(node24,QPointF(640,165)));
    //dodavanje suseda za node24
    QVector<int> node24_neighbours = {13,25};
    node24->set_all_neighbours(node24_neighbours);

    //donji desni cetvrtog

    const auto node25 = new Node(25);
    m_nodes.push_back(node25);
    m_gui_nodes.push_back(new GUI_Node(node25,QPointF(640,240)));
    //dodavanje suseda za node25
    QVector<int> node25_neighbours = {23,24,37};
    node25->set_all_neighbours(node25_neighbours);

    //TRECI RED

    //gornji levi prvog

    const auto node26 = new Node(26);
    m_nodes.push_back(node26);
    m_gui_nodes.push_back(new GUI_Node(node26,QPointF(57,275)));
    //dodavanje suseda za node26
    QVector<int> node26_neighbours = {16,27};
    node26->set_all_neighbours(node26_neighbours);

    //donji levi prvog

    const auto node27 = new Node(27);
    m_nodes.push_back(node27);
    m_gui_nodes.push_back(new GUI_Node(node27,QPointF(57,350)));
    //dodavanje suseda za node27
    QVector<int> node27_neighbours = {26,28};
    node27->set_all_neighbours(node27_neighbours);

    //dno prvog

    const auto node28 = new Node(28);
    m_nodes.push_back(node28);
    m_gui_nodes.push_back(new GUI_Node(node28,QPointF(122,380)));
    //dodavanje suseda za node28
    QVector<int> node28_neighbours = {27,29,39};
    node28->set_all_neighbours(node28_neighbours);

    //donji desni prvog

    const auto node29 = new Node(29);
    m_nodes.push_back(node29);
    m_gui_nodes.push_back(new GUI_Node(node29,QPointF(187,350)));
    //dodavanje suseda za node29
    QVector<int> node29_neighbours = {17,28,30};
    node29->set_all_neighbours(node29_neighbours);


    //donji drugog

    const auto node30 = new Node(30);
    m_nodes.push_back(node30);
    m_gui_nodes.push_back(new GUI_Node(node30,QPointF(252,380)));
    //dodavanje suseda za node30
    QVector<int> node30_neighbours = {29,31,41};
    node30->set_all_neighbours(node30_neighbours);

    //donji desni drugog

    const auto node31 = new Node(31);
    m_nodes.push_back(node31);
    m_gui_nodes.push_back(new GUI_Node(node31,QPointF(317,350)));
    //dodavanje suseda za node31
    QVector<int> node31_neighbours = {19,30,32};
    node31->set_all_neighbours(node31_neighbours);

    //donji treceg

    const auto node32 = new Node(32);
    m_nodes.push_back(node32);
    m_gui_nodes.push_back(new GUI_Node(node32,QPointF(382,380)));
    //dodavanje suseda za node32
    QVector<int> node32_neighbours = {31,33,43};
    node32->set_all_neighbours(node32_neighbours);

    //donji desni treceg

    const auto node33 = new Node(33);
    m_nodes.push_back(node33);
    m_gui_nodes.push_back(new GUI_Node(node33,QPointF(447,350)));
    //dodavanje suseda za node33
    QVector<int> node33_neighbours = {21,32,34};
    node33->set_all_neighbours(node33_neighbours);

    //donji cetvrtog

    const auto node34 = new Node(34);
    m_nodes.push_back(node34);
    m_gui_nodes.push_back(new GUI_Node(node34,QPointF(512,380)));
    //dodavanje suseda za node34
    QVector<int> node34_neighbours = {33,35,45};
    node34->set_all_neighbours(node34_neighbours);

    //donji desni cetvrtog

    const auto node35 = new Node(35);
    m_nodes.push_back(node35);
    m_gui_nodes.push_back(new GUI_Node(node35,QPointF(577,350)));
    //dodavanje suseda za node20
    QVector<int> node35_neighbours = {23,34,36};
    node35->set_all_neighbours(node35_neighbours);

    //donji petog

    const auto node36 = new Node(36);
    m_nodes.push_back(node36);
    m_gui_nodes.push_back(new GUI_Node(node36,QPointF(642,380)));
    //dodavanje suseda za node36
    QVector<int> node36_neighbours = {35,37,47};
    node36->set_all_neighbours(node36_neighbours);

    //donji desni petog

    const auto node37 = new Node(37);
    m_nodes.push_back(node37);
    m_gui_nodes.push_back(new GUI_Node(node37,QPointF(707,350)));
    //dodavanje suseda za node37
    QVector<int> node37_neighbours = {36,38};
    node37->set_all_neighbours(node37_neighbours);

    //gornji desni petog

    const auto node38 = new Node(38);
    m_nodes.push_back(node38);
    m_gui_nodes.push_back(new GUI_Node(node38,QPointF(707,275)));
    //dodavanje suseda za node38
    QVector<int> node38_neighbours = {25,37};
    node38->set_all_neighbours(node38_neighbours);

    //CETVRTI RED

    //donji levi prvog

    const auto node39 = new Node(39);
    m_nodes.push_back(node39);
    m_gui_nodes.push_back(new GUI_Node(node39,QPointF(122,460)));
    //dodavanje suseda za node39
    QVector<int> node39_neighbours = {28,40};
    node39->set_all_neighbours(node39_neighbours);

    //dno prvog

    const auto node40 = new Node(40);
    m_nodes.push_back(node40);
    m_gui_nodes.push_back(new GUI_Node(node40,QPointF(187,500)));
    //dodavanje suseda za node40
    QVector<int> node40_neighbours = {39,41};
    node40->set_all_neighbours(node40_neighbours);

    //donji desni prvog

    const auto node41 = new Node(41);
    m_nodes.push_back(node41);
    m_gui_nodes.push_back(new GUI_Node(node41,QPointF(252,460)));
    //dodavanje suseda za node41
    QVector<int> node41_neighbours = {30,40,42};
    node41->set_all_neighbours(node41_neighbours);


    //dno drugog

    const auto node42 = new Node(42);
    m_nodes.push_back(node42);
    m_gui_nodes.push_back(new GUI_Node(node42,QPointF(317,500)));
    //dodavanje suseda za node42
    QVector<int> node42_neighbours = {41,43,50};
    node42->set_all_neighbours(node42_neighbours);

    //donji desni prvog

    const auto node43 = new Node(43);
    m_nodes.push_back(node43);
    m_gui_nodes.push_back(new GUI_Node(node43,QPointF(382,460)));
    //dodavanje suseda za node43
    QVector<int> node43_neighbours = {32,42,44};
    node43->set_all_neighbours(node43_neighbours);


    //dno treceg

    const auto node44 = new Node(44);
    m_nodes.push_back(node44);
    m_gui_nodes.push_back(new GUI_Node(node44,QPointF(447,500)));
    //dodavanje suseda za node44
    QVector<int> node44_neighbours = {43,45,52};
    node44->set_all_neighbours(node44_neighbours);

    //donji desni treceg

    const auto node45 = new Node(45);
    m_nodes.push_back(node45);
    m_gui_nodes.push_back(new GUI_Node(node45,QPointF(512,460)));
    //dodavanje suseda za node45
    QVector<int> node45_neighbours = {34,44,46};
    node45->set_all_neighbours(node45_neighbours);

    //dno cetvrtog

    const auto node46 = new Node(46);
    m_nodes.push_back(node46);
    m_gui_nodes.push_back(new GUI_Node(node46,QPointF(577,500)));
    //dodavanje suseda za node46
    QVector<int> node46_neighbours = {45,47,54};
    node46->set_all_neighbours(node46_neighbours);

    //donji desni prvog

    const auto node47 = new Node(47);
    m_nodes.push_back(node47);
    m_gui_nodes.push_back(new GUI_Node(node47,QPointF(642,460)));
    //dodavanje suseda za node47
    QVector<int> node47_neighbours = {36,46};
    node47->set_all_neighbours(node47_neighbours);


    //peti red

    //donji levi prvog

    const auto node48 = new Node(48);
    m_nodes.push_back(node48);
    m_gui_nodes.push_back(new GUI_Node(node48,QPointF(187,575)));
    //dodavanje suseda za node48
    QVector<int> node48_neighbours = {40,49};
    node48->set_all_neighbours(node48_neighbours);

    //dno prvog

    const auto node49 = new Node(49);
    m_nodes.push_back(node49);
    m_gui_nodes.push_back(new GUI_Node(node49,QPointF(250,600)));
    //dodavanje suseda za node49
    QVector<int> node49_neighbours = {48,50};
    node49->set_all_neighbours(node49_neighbours);

    //donji desni prvog
    const auto node50 = new Node(50);
    m_nodes.push_back(node50);
    m_gui_nodes.push_back(new GUI_Node(node50,QPointF(317,575)));
    //dodavanje suseda za node50
    QVector<int> node50_neighbours = {42,49,51};
    node50->set_all_neighbours(node50_neighbours);


    //dno drugog

    const auto node51= new Node(51);
    m_nodes.push_back(node51);
    m_gui_nodes.push_back(new GUI_Node(node51,QPointF(380,600)));
    //dodavanje suseda za node51
    QVector<int> node51_neighbours = {50,52};
    node51->set_all_neighbours(node51_neighbours);

    //donji desni prvog
    const auto node52 = new Node(52);
    m_nodes.push_back(node52);
    m_gui_nodes.push_back(new GUI_Node(node52,QPointF(444,575)));
    //dodavanje suseda za node52
    QVector<int> node52_neighbours = {44,51,53};
    node52->set_all_neighbours(node52_neighbours);

    //dno treceg

    const auto node53= new Node(53);
    m_nodes.push_back(node53);
    m_gui_nodes.push_back(new GUI_Node(node53,QPointF(510,600)));
    //dodavanje suseda za node53
    QVector<int> node53_neighbours = {52,54};
    node53->set_all_neighbours(node53_neighbours);

    //donji desni treceg
    const auto node54 = new Node(54);
    m_nodes.push_back(node54);
    m_gui_nodes.push_back(new GUI_Node(node54,QPointF(575,575)));
    //dodavanje suseda za node54
    QVector<int> node54_neighbours = {46,53};
    node54->set_all_neighbours(node54_neighbours);


    for(int i=0;i<54;i++)
          addItem(m_gui_nodes[i]);
    //fields
    //const auto Field1 = new Field(1,10,node1,node2,node3,node4,node5,node6);

}

/*
void Board::SetNodeOnPosition(GUI_Node *node)
{
    const auto boardWidth = static_cast<int>(this->width());

    node->setPos(100,100);
}
*/
void Board::addAllFields(){
    addAllNodes();
    //prvi red
    const auto Field1 = new Field(1,10,m_nodes[1],m_nodes[2],m_nodes[3],m_nodes[4],m_nodes[5],m_nodes[6]);
    Field1->set_res_type(ResourceType::Stone);
    m_fields.push_back(Field1);

    const auto Field2 = new Field(2,8,m_nodes[3],m_nodes[7],m_nodes[8],m_nodes[9],m_nodes[10], m_nodes[4]);
    Field2->set_res_type(ResourceType::Brick);
    m_fields.push_back(Field2);

    const auto Field3 = new Field(3,3,m_nodes[8],m_nodes[11],m_nodes[12],m_nodes[13],m_nodes[14],m_nodes[9]);
    Field3->set_res_type(ResourceType::Wood);
    m_fields.push_back(Field3);

    //drugi red
    const auto Field4 = new Field(4,2,m_nodes[15],m_nodes[6],m_nodes[5], m_nodes[18], m_nodes[17], m_nodes[16]);
    Field4->set_res_type(ResourceType::Wheat);
    m_fields.push_back(Field4);

    const auto Field5 = new Field(5,3,m_nodes[5],m_nodes[4],m_nodes[10],m_nodes[20],m_nodes[19],m_nodes[18]);
    Field5->set_res_type(ResourceType::Wool);
    m_fields.push_back(Field5);

    const auto Field6 = new Field(6,9,m_nodes[10],m_nodes[9],m_nodes[14],m_nodes[22],m_nodes[21],m_nodes[20]);
    Field6->set_res_type(ResourceType::Brick);
    m_fields.push_back(Field6);

    const auto Field7 = new Field(7,4,m_nodes[14],m_nodes[13],m_nodes[24],m_nodes[25],m_nodes[23],m_nodes[22]);
    Field7->set_res_type(ResourceType::Brick);
    m_fields.push_back(Field7);

    //treci red
    const auto Field8 = new Field(8,12,m_nodes[26],m_nodes[16],m_nodes[17],m_nodes[29],m_nodes[28],m_nodes[27]);
    Field8->set_res_type(ResourceType::Wool);
    m_fields.push_back(Field8);

    const auto Field9 = new Field(9,8,m_nodes[17],m_nodes[18],m_nodes[19],m_nodes[31],m_nodes[30],m_nodes[29]);
    Field9->set_res_type(ResourceType::Stone);
    m_fields.push_back(Field9);

    const auto Field10 = new Field(10,4,m_nodes[19],m_nodes[20],m_nodes[21],m_nodes[33],m_nodes[32],m_nodes[31]);
    Field10->set_res_type(ResourceType::Stone);
    m_fields.push_back(Field10);

    const auto Field11 = new Field(11,6,m_nodes[21],m_nodes[22],m_nodes[23],m_nodes[35],m_nodes[34],m_nodes[33]);
    Field11->set_res_type(ResourceType::Wood);
    m_fields.push_back(Field11);

    const auto Field12 = new Field(12,11,m_nodes[23],m_nodes[25],m_nodes[38],m_nodes[37],m_nodes[36],m_nodes[25]);
    Field12->set_res_type(ResourceType::Wheat);
    m_fields.push_back(Field12);

    //cetvrti red
    const auto Field13 = new Field(13,9,m_nodes[28],m_nodes[29],m_nodes[30],m_nodes[41],m_nodes[40],m_nodes[39]);
    Field13->set_res_type(ResourceType::Wheat);
    m_fields.push_back(Field13);

    const auto Field14 = new Field(14,5,m_nodes[30],m_nodes[31],m_nodes[32],m_nodes[43],m_nodes[42],m_nodes[41]);
    Field14->set_res_type(ResourceType::Wood);
    m_fields.push_back(Field14);

    const auto Field15 = new Field(15,11,m_nodes[32],m_nodes[33],m_nodes[34],m_nodes[45],m_nodes[44],m_nodes[43]);
    Field15->set_res_type(ResourceType::Wool);
    m_fields.push_back(Field15);

    const auto Field16 = new Field(16,5,m_nodes[34],m_nodes[35],m_nodes[36],m_nodes[47],m_nodes[46],m_nodes[45]);
    Field16->set_res_type(ResourceType::Wood);
    m_fields.push_back(Field16);

    //peti red
    const auto Field17 = new Field(17,6,m_nodes[40],m_nodes[41],m_nodes[42],m_nodes[50],m_nodes[49],m_nodes[48]);
    Field17->set_res_type(ResourceType::Wheat);
    m_fields.push_back(Field17);

    const auto Field18 = new Field(18,10,m_nodes[42],m_nodes[43],m_nodes[44],m_nodes[52],m_nodes[51],m_nodes[50]);
    Field18->set_res_type(ResourceType::Wheat);
    m_fields.push_back(Field18);

    //poslednje polje je pustinja pa cu staviti da je na njemu broj = 0,takodje nema tip resursa
    const auto Field19 = new Field(19,0,m_nodes[44],m_nodes[45],m_nodes[46],m_nodes[54],m_nodes[53],m_nodes[52]);
    m_fields.push_back(Field19);
}

