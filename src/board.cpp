#include "board.h"
#include "node.h"
#include "gui_node.h"
#include <iostream>
#include "field.h"
#include <QColor>

Board::Board(QObject *parent): QGraphicsScene(parent){}

Board::~Board(){
    for(auto &node : m_nodes){
        delete node;
    }
    m_nodes.clear();
}

QVector<Field *>Board::get_fields(){
    return m_fields;
}

void Board::addAllNodes(){

    /*prvi heksagon prvi red */

    //gornji levi ugao prvog heksagona njegovi susedi su - prvi ispod njega po y osi (185,130) i vrh heksagona (250,20)
    const auto node1 = new Node(1);
    QVector<int> node1_neighbours = {2,6};
    node1->set_all_neighbours(node1_neighbours);
    m_nodes.push_back(node1);
   // m_gui_nodes.push_back(new GUI_Node(node1,QPointF(185,55)));
    const auto gnode1 = new GUI_Node(node1);
    gnode1->setPos(185,55);
    m_gui_nodes.push_back(gnode1);



    const auto node2 = new Node(2);
    QVector<int> node2_neighbours = {1,3};
    node2->set_all_neighbours(node2_neighbours);
    m_nodes.push_back(node2);
    const auto gnode2 = new GUI_Node(node2);
    gnode2->setPos(250,20);
    m_gui_nodes.push_back(gnode2);

    const auto node3 = new Node(3);
    QVector<int> node3_neighbours = {2,4,7};
    node3->set_all_neighbours(node3_neighbours);
    m_nodes.push_back(node3);
    const auto gnode3 = new GUI_Node(node3);
    gnode3->setPos(315,55);
    m_gui_nodes.push_back(gnode3);
    //vrh prvog heksagona njegovi susedi su - (185,130),(315,55)
//    const auto node2 = new Node(2);
//    m_nodes.push_back(node2);
//    m_gui_nodes.push_back(new GUI_Node(node2,QPointF(250,20)));

//    //gornji desni prvog heksagona, susedi su (250,20),(315,130),(380,20)
//    const auto node3 = new Node(3);
//    m_nodes.push_back(node3);
//    m_gui_nodes.push_back(new GUI_Node(node3,QPointF(315,55)));

    //donji desni prvog heksagona, susedi su (315,55),(250,165),(380,165)
    const auto node4 = new Node(4);
    QVector<int> node4_neighbours = {3,5,10};
    node4->set_all_neighbours(node4_neighbours);
    m_nodes.push_back(node4);
    const auto gnode4 = new GUI_Node(node4);
    gnode4->setPos(315,130);
    m_gui_nodes.push_back(gnode4);


    //dno prvog heksagona, susedi su (315,130),(185,130),(250,240)
    const auto node5 = new Node(5);
    QVector<int> node5_neighbours = {4,6,18};
    node5->set_all_neighbours(node5_neighbours);
    m_nodes.push_back(node5);
    const auto gnode5 = new GUI_Node(node5);
    gnode5->setPos(250,165);
    m_gui_nodes.push_back(gnode5);


    //donji levi prvog heksagona susedi su (185,55),(250,165)
    const auto node6 = new Node(6);
    QVector<int> node6_neighbours = {1,5,15};
    node6->set_all_neighbours(node6_neighbours);
    m_nodes.push_back(node6);
    const auto gnode6 = new GUI_Node(node6);
    gnode6->setPos(185,130);
    m_gui_nodes.push_back(gnode6);

    /*DRUGI HEKSAGON PRVI RED*/

    //vrh drugog heksagona susedi su (315,15),(445,55)
    const auto node7 = new Node(7);
    QVector<int> node7_neighbours = {3,8};
    node7->set_all_neighbours(node7_neighbours);
    m_nodes.push_back(node7);
    const auto gnode7 = new GUI_Node(node7);
    gnode7->setPos(380,20);
    m_gui_nodes.push_back(gnode7);

    //gornji desni ugao heksagona susedi su (510,20),(445,130)
    const auto node8 = new Node(8);
    QVector<int> node8_neighbours = {7,9,11};
    node8->set_all_neighbours(node8_neighbours);
    m_nodes.push_back(node8);
    const auto gnode8 = new GUI_Node(node8);
    gnode8->setPos(445,55);
    m_gui_nodes.push_back(gnode8);

    //donji desni heksagona, susedi su (445,55),(250,165),(380,165)
    const auto node9 = new Node(9);
    QVector<int> node9_neighbours = {8,10,14};
    node9->set_all_neighbours(node9_neighbours);
    m_nodes.push_back(node9);
    const auto gnode9 = new GUI_Node(node9);
    gnode9->setPos(445,130);
    m_gui_nodes.push_back(gnode9);

    //dno heksagona susedi (215,130),(340,130),(380,240)
    const auto node10 = new Node(10);
    QVector<int> node10_neighbours = {4,9,20};
    node10->set_all_neighbours(node10_neighbours);
    m_nodes.push_back(node10);
    const auto gnode10 = new GUI_Node(node10);
    gnode10->setPos(380,165);
    m_gui_nodes.push_back(gnode10);

    //treci heksagon

    //vrh treceg heksagona prvi red
    const auto node11 = new Node(11);
    QVector<int> node11_neighbours = {8,12};
    node11->set_all_neighbours(node11_neighbours);
    m_nodes.push_back(node11);
    const auto gnode11 = new GUI_Node(node11);
    gnode11->setPos(510,20);
    m_gui_nodes.push_back(gnode11);

    //gornji desni treceg heksagona treceg
    const auto node12 = new Node(12);
    QVector<int> node12_neighbours = {11,13};
    node12->set_all_neighbours(node12_neighbours);
    m_nodes.push_back(node12);
    const auto gnode12 = new GUI_Node(node12);
    gnode12->setPos(575,55);
    m_gui_nodes.push_back(gnode12);

    //donji desni treceg heksagona treceg
    const auto node13 = new Node(13);
    QVector<int> node13_neighbours = {12,14,24};
    node13->set_all_neighbours(node13_neighbours);
    m_nodes.push_back(node13);
    const auto gnode13 = new GUI_Node(node13);
    gnode13->setPos(575,130);
    m_gui_nodes.push_back(gnode13);

    //dno treceg heksagona prvi red
    const auto node14 = new Node(14);
    QVector<int> node14_neighbours = {9,13,22};
    node14->set_all_neighbours(node14_neighbours);
    m_nodes.push_back(node14);
    const auto gnode14 = new GUI_Node(node14);
    gnode14->setPos(510,165);
    m_gui_nodes.push_back(gnode14);


    //drugi red

    //gornji levi u prvom heksagonu
    const auto node15 = new Node(15);
    QVector<int> node15_neighbours = {6,16};
    node15->set_all_neighbours(node15_neighbours);
    m_nodes.push_back(node15);
    const auto gnode15 = new GUI_Node(node15);
    gnode15->setPos(120,165);
    m_gui_nodes.push_back(gnode15);

    //donji levi u prvom heksagonu
    const auto node16 = new Node(16);
    QVector<int> node16_neighbours = {15,17,26};
    node16->set_all_neighbours(node16_neighbours);
    m_nodes.push_back(node16);
    const auto gnode16 = new GUI_Node(node16);
    gnode16->setPos(120,240);
    m_gui_nodes.push_back(gnode16);


    //dno prvog heksagona

    const auto node17 = new Node(17);
    QVector<int> node17_neighbours = {16,18,29};
    node17->set_all_neighbours(node17_neighbours);
    m_nodes.push_back(node17);
    const auto gnode17 = new GUI_Node(node17);
    gnode17->setPos(185,270);
    m_gui_nodes.push_back(gnode17);

    //donji desni prvog heksagona

    const auto node18 = new Node(18);
    QVector<int> node18_neighbours = {5,17,19};
    node18->set_all_neighbours(node18_neighbours);
    m_nodes.push_back(node18);
    const auto gnode18 = new GUI_Node(node18);
    gnode18->setPos(250,240);
    m_gui_nodes.push_back(gnode18);


    //drugi heksagon drugi red

    //dno heksagona

    const auto node19 = new Node(19);
    QVector<int> node19_neighbours = {18,20,31};
    node19->set_all_neighbours(node19_neighbours);
    m_nodes.push_back(node19);
    const auto gnode19 = new GUI_Node(node19);
    gnode19->setPos(315,270);
    m_gui_nodes.push_back(gnode19);

    //donji desni drugog

    const auto node20 = new Node(20);
    QVector<int> node20_neighbours = {10,19,21};
    node20->set_all_neighbours(node20_neighbours);
    m_nodes.push_back(node20);
    const auto gnode20 = new GUI_Node(node20);
    gnode20->setPos(380,240);
    m_gui_nodes.push_back(gnode20);


    //treci

    //dno treceg

    const auto node21 = new Node(21);
    QVector<int> node21_neighbours = {20,22,33};
    node21->set_all_neighbours(node21_neighbours);
    m_nodes.push_back(node21);
    const auto gnode21 = new GUI_Node(node21);
    gnode21->setPos(445,270);
    m_gui_nodes.push_back(gnode21);

    //donji desni treceg

    const auto node22 = new Node(22);
    QVector<int> node22_neighbours = {14,21,23};
    node22->set_all_neighbours(node22_neighbours);
    m_nodes.push_back(node22);
    const auto gnode22 = new GUI_Node(node22);
    gnode22->setPos(510,240);
    m_gui_nodes.push_back(gnode22);

    //cetvrti

    //dno cetvrtog


    const auto node23 = new Node(23);
    QVector<int> node23_neighbours = {22,25,35};
    node23->set_all_neighbours(node23_neighbours);
    m_nodes.push_back(node23);
    const auto gnode23 = new GUI_Node(node23);
    gnode23->setPos(575,270);
    m_gui_nodes.push_back(gnode23);

    //gornji desni cetvrtog
    const auto node24 = new Node(24);
    QVector<int> node24_neighbours = {13,25};
    node24->set_all_neighbours(node24_neighbours);
    m_nodes.push_back(node24);
    const auto gnode24 = new GUI_Node(node24);
    gnode24->setPos(640,165);
    m_gui_nodes.push_back(gnode24);

    //donji desni cetvrtog

    const auto node25 = new Node(25);
    QVector<int> node25_neighbours = {23,24,37};
    node25->set_all_neighbours(node25_neighbours);
    m_nodes.push_back(node25);
    const auto gnode25 = new GUI_Node(node25);
    gnode25->setPos(640,240);
    m_gui_nodes.push_back(gnode25);


    //TRECI RED

    //gornji levi prvog

    const auto node26 = new Node(26);
    QVector<int> node26_neighbours = {16,27};
    node26->set_all_neighbours(node26_neighbours);
    m_nodes.push_back(node26);
    const auto gnode26 = new GUI_Node(node26);
    gnode26->setPos(57,275);
    m_gui_nodes.push_back(gnode26);

    //donji levi prvog

    const auto node27 = new Node(27);
    QVector<int> node27_neighbours = {26,28};
    node27->set_all_neighbours(node27_neighbours);
    m_nodes.push_back(node27);
    const auto gnode27 = new GUI_Node(node27);
    gnode27->setPos(57,350);
    m_gui_nodes.push_back(gnode27);

    //dno prvog

    const auto node28 = new Node(28);
    QVector<int> node28_neighbours = {27,29,39};
    node28->set_all_neighbours(node28_neighbours);
    m_nodes.push_back(node28);
    const auto gnode28 = new GUI_Node(node28);
    gnode28->setPos(122,380);
    m_gui_nodes.push_back(gnode28);

    //donji desni prvog

    const auto node29 = new Node(29);
    QVector<int> node29_neighbours = {17,28,30};
    node29->set_all_neighbours(node29_neighbours);
    m_nodes.push_back(node29);
    const auto gnode29 = new GUI_Node(node29);
    gnode29->setPos(187,350);
    m_gui_nodes.push_back(gnode29);


    //donji drugog

    const auto node30 = new Node(30);
    QVector<int> node30_neighbours = {29,31,41};
    node30->set_all_neighbours(node30_neighbours);
    m_nodes.push_back(node30);
    const auto gnode30 = new GUI_Node(node30);
    gnode30->setPos(252,380);
    m_gui_nodes.push_back(gnode30);

    //donji desni drugog

    const auto node31 = new Node(31);
    QVector<int> node31_neighbours = {19,30,32};
    node31->set_all_neighbours(node31_neighbours);
    m_nodes.push_back(node31);
    const auto gnode31 = new GUI_Node(node31);
    gnode31->setPos(317,350);
    m_gui_nodes.push_back(gnode31);

    //donji treceg

    const auto node32 = new Node(32);
    QVector<int> node32_neighbours = {31,33,43};
    node32->set_all_neighbours(node32_neighbours);
    m_nodes.push_back(node32);
    const auto gnode32 = new GUI_Node(node32);
    gnode32->setPos(382,380);
    m_gui_nodes.push_back(gnode32);

    //donji desni treceg

    const auto node33 = new Node(33);
    QVector<int> node33_neighbours = {21,32,34};
    node33->set_all_neighbours(node33_neighbours);
    m_nodes.push_back(node33);
    const auto gnode33 = new GUI_Node(node33);
    gnode33->setPos(447,350);
    m_gui_nodes.push_back(gnode33);


    //donji cetvrtog

    const auto node34 = new Node(34);
    QVector<int> node34_neighbours = {33,35,45};
    node34->set_all_neighbours(node34_neighbours);
    m_nodes.push_back(node34);
    const auto gnode34 = new GUI_Node(node34);
    gnode34->setPos(512,380);
    m_gui_nodes.push_back(gnode34);

    //donji desni cetvrtog

    const auto node35 = new Node(35);
    QVector<int> node35_neighbours = {23,34,36};
    node35->set_all_neighbours(node35_neighbours);
    m_nodes.push_back(node35);
    const auto gnode35 = new GUI_Node(node35);
    gnode35->setPos(577,350);
    m_gui_nodes.push_back(gnode35);

    //donji petog

    const auto node36 = new Node(36);
    QVector<int> node36_neighbours = {35,37,47};
    node36->set_all_neighbours(node36_neighbours);
    m_nodes.push_back(node36);
    const auto gnode36 = new GUI_Node(node36);
    gnode36->setPos(642,380);
    m_gui_nodes.push_back(gnode36);

    //donji desni petog

    const auto node37 = new Node(37);
    QVector<int> node37_neighbours = {36,38};
    node37->set_all_neighbours(node37_neighbours);
    m_nodes.push_back(node37);
    const auto gnode37 = new GUI_Node(node37);
    gnode37->setPos(707,350);
    m_gui_nodes.push_back(gnode37);

    //gornji desni petog

    const auto node38 = new Node(38);
    QVector<int> node38_neighbours = {25,37};
    node38->set_all_neighbours(node38_neighbours);
    m_nodes.push_back(node38);
    const auto gnode38 = new GUI_Node(node38);
    gnode38->setPos(707,275);
    m_gui_nodes.push_back(gnode38);

    //CETVRTI RED

    //donji levi prvog

    const auto node39 = new Node(39);
    QVector<int> node39_neighbours = {28,40};
    node39->set_all_neighbours(node39_neighbours);
    m_nodes.push_back(node39);
    const auto gnode39 = new GUI_Node(node39);
    gnode39->setPos(122,460);
    m_gui_nodes.push_back(gnode39);


    //dno prvog

    const auto node40 = new Node(40);
    QVector<int> node40_neighbours = {39,41};
    node40->set_all_neighbours(node40_neighbours);
    m_nodes.push_back(node40);
    const auto gnode40 = new GUI_Node(node40);
    gnode40->setPos(187,500);
    m_gui_nodes.push_back(gnode40);

    //donji desni prvog

    const auto node41 = new Node(41);
    QVector<int> node41_neighbours = {30,40,42};
    node41->set_all_neighbours(node41_neighbours);
    m_nodes.push_back(node41);
    const auto gnode41 = new GUI_Node(node41);
    gnode41->setPos(252,460);
    m_gui_nodes.push_back(gnode41);



    //dno drugog

    const auto node42 = new Node(42);
    QVector<int> node42_neighbours = {41,43,50};
    node42->set_all_neighbours(node42_neighbours);
    m_nodes.push_back(node42);
    const auto gnode42 = new GUI_Node(node42);
    gnode42->setPos(317,500);
    m_gui_nodes.push_back(gnode42);

    //donji desni prvog

    const auto node43 = new Node(43);
    QVector<int> node43_neighbours = {32,42,44};
    node43->set_all_neighbours(node43_neighbours);
    m_nodes.push_back(node43);
    const auto gnode43 = new GUI_Node(node43);
    gnode43->setPos(382,460);
    m_gui_nodes.push_back(gnode43);


    //dno treceg

    const auto node44 = new Node(44);
    QVector<int> node44_neighbours = {43,45,52};
    node44->set_all_neighbours(node44_neighbours);
    m_nodes.push_back(node44);
    const auto gnode44 = new GUI_Node(node44);
    gnode44->setPos(447,500);
    m_gui_nodes.push_back(gnode44);

    //donji desni treceg

    const auto node45 = new Node(45);
    QVector<int> node45_neighbours = {34,44,46};
    node45->set_all_neighbours(node45_neighbours);
    m_nodes.push_back(node45);
    const auto gnode45 = new GUI_Node(node45);
    gnode45->setPos(512,460);
    m_gui_nodes.push_back(gnode45);


    //dno cetvrtog

    const auto node46 = new Node(46);
    QVector<int> node46_neighbours = {45,47,54};
    node46->set_all_neighbours(node46_neighbours);
    m_nodes.push_back(node46);
    const auto gnode46 = new GUI_Node(node46);
    gnode46->setPos(577,500);
    m_gui_nodes.push_back(gnode46);

    //donji desni prvog

    const auto node47 = new Node(47);
    QVector<int> node47_neighbours = {36,46};
    node47->set_all_neighbours(node47_neighbours);
    m_nodes.push_back(node47);
    const auto gnode47 = new GUI_Node(node47);
    gnode47->setPos(642,460);
    m_gui_nodes.push_back(gnode47);


    //peti red

    //donji levi prvog

    const auto node48 = new Node(48);
    QVector<int> node48_neighbours = {40,49};
    node48->set_all_neighbours(node48_neighbours);
    m_nodes.push_back(node48);
    const auto gnode48 = new GUI_Node(node48);
    gnode48->setPos(187,575);
    m_gui_nodes.push_back(gnode48);

    //dno prvog

    const auto node49 = new Node(49);
    QVector<int> node49_neighbours = {48,50};
    node49->set_all_neighbours(node49_neighbours);
    m_nodes.push_back(node49);
    const auto gnode49 = new GUI_Node(node49);
    gnode49->setPos(250,600);
    m_gui_nodes.push_back(gnode49);

    //donji desni prvog
    const auto node50 = new Node(50);
    QVector<int> node50_neighbours = {42,49,51};
    node50->set_all_neighbours(node50_neighbours);
    m_nodes.push_back(node50);
    const auto gnode50 = new GUI_Node(node50);
    gnode50->setPos(317,575);
    m_gui_nodes.push_back(gnode50);



    //dno drugog

    const auto node51= new Node(51);
    QVector<int> node51_neighbours = {50,52};
    node51->set_all_neighbours(node51_neighbours);
    m_nodes.push_back(node51);
    const auto gnode51 = new GUI_Node(node51);
    gnode51->setPos(380,600);
    m_gui_nodes.push_back(gnode51);

    //donji desni prvog
    const auto node52 = new Node(52);
    QVector<int> node52_neighbours = {44,51,53};
    node52->set_all_neighbours(node52_neighbours);
    m_nodes.push_back(node52);
    const auto gnode52 = new GUI_Node(node52);
    gnode52->setPos(444,575);
    m_gui_nodes.push_back(gnode52);


    //dno treceg

    const auto node53= new Node(53);
    QVector<int> node53_neighbours = {52,54};
    node53->set_all_neighbours(node53_neighbours);
    m_nodes.push_back(node53);
    const auto gnode53 = new GUI_Node(node53);
    gnode53->setPos(510,600);
    m_gui_nodes.push_back(gnode53);

    //donji desni treceg
    const auto node54 = new Node(54);
    QVector<int> node54_neighbours = {46,53};
    node54->set_all_neighbours(node54_neighbours);
    m_nodes.push_back(node54);
    const auto gnode54 = new GUI_Node(node54);
    gnode54->setPos(575,575);
    m_gui_nodes.push_back(gnode54);


//    for(int i=0;i<54;i++){
//        connect(m_gui_nodes[i],&GUI_Node::needRedraw,this,&Board::Redraw);
//        addItem(m_gui_nodes[i]);

//    }
//    connect(gnode1,&GUI_Node::needRedraw,this,&Board::Redraw);
//    addItem(gnode1);
//    connect(gnode2,&GUI_Node::needRedraw,this,&Board::Redraw);
//    addItem(gnode2);
//    connect(gnode3,&GUI_Node::needRedraw,this,&Board::Redraw);
//    addItem(gnode3);
    for(int i=0;i<54;i++){
        connect(m_gui_nodes[i],&GUI_Node::needRedraw,this,&Board::Redraw); //slicno ovom hoveru i signalu treba da se uradi sa iscrtavanjem kuce odredjenog igraca

        //tj. u fji set house/ city se baca signal needRedraw
        //ali bitna napomena, sva crtanja kuca/grad itd se rade u okviru mousepressevent funkcije, samo se razlicito pisu uslovi i to je to
        addItem(m_gui_nodes[i]);
    }

}


void Board::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //treba dodati if isto ovo dole == null da ne radi nista, da ne bi bacao signal za prekid rada
    //treba dodati u ovaj donji if, if pbRoadEnabled && itemAt...
    if(m_setRoad && itemAt(event->scenePos(), QTransform())->type() == 1){
            if(!m_hasTmp){
                this->m_tmp = dynamic_cast<GUI_Node*>(itemAt(event->scenePos(), QTransform()));
                Node* node = m_tmp->getNode();
                if (this->m_tmp->get_is_end_of_road()) { setHasTmp(true); }
            }
            else{
                GUI_Node *node = dynamic_cast<GUI_Node*>(itemAt(event->scenePos(), QTransform()));
                node->set_hasRoad(true);
                if((m_tmp->get_is_house_built() || m_tmp->get_hasRoad()) && m_tmp != node) {
                    GUI_Road* road = new GUI_Road(m_tmp, node);
                    road->set_pen(getRoadColor());
                    addItem(road);
                    node->set_is_end_of_road(true);
                    m_setRoad = false;


                    //emit addedNewEdge(m_tmp->getNode(), node->getNode(), 1);
                }

                setHasTmp(false);
            }
        }

    //kliknuto dugme za kucu (u mainwindow je implementacija) pa moze da se crta
    if(m_setHouse && (itemAt(event->scenePos(),QTransform())->type()==1)){
        Redraw();
        GUI_Node *gui_node = dynamic_cast<GUI_Node*>(itemAt(event->scenePos(),QTransform()));
        //provera za node da li na susednim cvorovima ima izgradjenih obejkata
        auto node_neighbours = gui_node->Node_get()->get_neighbours();
        int neighbours_are_occupied = 0;
        for(auto &neighbour : node_neighbours){
            if(m_gui_nodes[neighbour-1]->get_is_house_built()){
                neighbours_are_occupied = 1;
                break;
            }
        }
        //prvo proveravamo da li nema nicega sagradjenog da mozemo da sagradimo kucu
        if (!gui_node->get_is_house_built() && neighbours_are_occupied == 0){
            gui_node->setBrush(QBrush(getCurrColor()));
            gui_node->set_is_house_built(true);
            gui_node->getNode()->set_is_house_built(true);
            //gui_node->getNode()->set_owner()
            //postavljanje ownera node-a kada sagradi kucu
            if (getCurrColor() == Qt::blue) {gui_node->getNode()->set_owner(1);}
            else if (getCurrColor() == Qt::yellow) {gui_node->getNode()->set_owner(2);}
            else if (getCurrColor() == Qt::green) {gui_node->getNode()->set_owner(3);}
            else  {gui_node->getNode()->set_owner(4);}
        }
        m_setHouse = false;
        gui_node->set_is_end_of_road(true);
        //emit nodeChanged();
        //connect(node,&Board::nodeChanged,this,&Board::Redraw);

    }
    //kliknuto dugme za city (u mainwindow je implementacija) pa moze da se crta
    if(m_setCity && (itemAt(event->scenePos(),QTransform())->type()==1)){
        Redraw();
        GUI_Node *node = dynamic_cast<GUI_Node*>(itemAt(event->scenePos(),QTransform()));
        //provera da li postoji kuca i da li ta kuca pripada igracu na potezu
        if (node->get_is_house_built() && node->check_owner_city(getCurrColor())){
            node->setBrush(QBrush(getCurrColor()));
            m_setCity = false;
        }
        //node->setBrush(QBrush(getCurrColor()));

    }

}


void Board::Redraw(){
    this->update();
}

void Board::setHasTmp(bool x){
    m_hasTmp = x;
}

void Board::setCurrColor(QColor color)
{
    m_curr_color = color;
}

QColor Board::getCurrColor()
{
    return m_curr_color;
}

void Board::setRoadColor(QColor color)
{
    m_road_color = color;
}

QColor Board::getRoadColor()
{
    return m_road_color;
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
        const auto Field1 = new Field(1,10,m_nodes[0],m_nodes[1],m_nodes[2],m_nodes[3],m_nodes[4],m_nodes[5]);
        Field1->set_res_type(ResourceType::Stone);
        m_fields.push_back(Field1);

        const auto Field2 = new Field(2,8,m_nodes[2],m_nodes[6],m_nodes[7],m_nodes[8],m_nodes[9], m_nodes[3]);
        Field2->set_res_type(ResourceType::Brick);
        m_fields.push_back(Field2);

        const auto Field3 = new Field(3,3,m_nodes[7],m_nodes[10],m_nodes[11],m_nodes[12],m_nodes[13],m_nodes[8]);
        Field3->set_res_type(ResourceType::Wood);
        m_fields.push_back(Field3);

        //drugi red
        const auto Field4 = new Field(4,2,m_nodes[14],m_nodes[5],m_nodes[4], m_nodes[17], m_nodes[16], m_nodes[15]);
        Field4->set_res_type(ResourceType::Wheat);
        m_fields.push_back(Field4);

        const auto Field5 = new Field(5,3,m_nodes[4],m_nodes[3],m_nodes[9],m_nodes[19],m_nodes[18],m_nodes[17]);
        Field5->set_res_type(ResourceType::Wool);
        m_fields.push_back(Field5);

        const auto Field6 = new Field(6,9,m_nodes[9],m_nodes[8],m_nodes[13],m_nodes[21],m_nodes[20],m_nodes[19]);
        Field6->set_res_type(ResourceType::Brick);
        m_fields.push_back(Field6);

        const auto Field7 = new Field(7,4,m_nodes[13],m_nodes[12],m_nodes[23],m_nodes[24],m_nodes[22],m_nodes[21]);
        Field7->set_res_type(ResourceType::Brick);
        m_fields.push_back(Field7);

        //treci red
        const auto Field8 = new Field(8,12,m_nodes[25],m_nodes[15],m_nodes[16],m_nodes[28],m_nodes[27],m_nodes[26]);
        Field8->set_res_type(ResourceType::Wool);
        m_fields.push_back(Field8);

        const auto Field9 = new Field(9,8,m_nodes[16],m_nodes[17],m_nodes[18],m_nodes[30],m_nodes[29],m_nodes[28]);
        Field9->set_res_type(ResourceType::Stone);
        m_fields.push_back(Field9);

        const auto Field10 = new Field(10,4,m_nodes[18],m_nodes[19],m_nodes[20],m_nodes[32],m_nodes[31],m_nodes[30]);
        Field10->set_res_type(ResourceType::Stone);
        m_fields.push_back(Field10);

        const auto Field11 = new Field(11,6,m_nodes[20],m_nodes[21],m_nodes[22],m_nodes[34],m_nodes[33],m_nodes[32]);
        Field11->set_res_type(ResourceType::Wood);
        m_fields.push_back(Field11);

        const auto Field12 = new Field(12,11,m_nodes[22],m_nodes[24],m_nodes[37],m_nodes[36],m_nodes[35],m_nodes[24]);
        Field12->set_res_type(ResourceType::Wheat);
        m_fields.push_back(Field12);

        //cetvrti red
        const auto Field13 = new Field(13,9,m_nodes[27],m_nodes[28],m_nodes[29],m_nodes[40],m_nodes[39],m_nodes[38]);
        Field13->set_res_type(ResourceType::Wheat);
        m_fields.push_back(Field13);

        const auto Field14 = new Field(14,5,m_nodes[29],m_nodes[30],m_nodes[31],m_nodes[42],m_nodes[41],m_nodes[40]);
        Field14->set_res_type(ResourceType::Wood);
        m_fields.push_back(Field14);

        const auto Field15 = new Field(15,11,m_nodes[31],m_nodes[32],m_nodes[33],m_nodes[44],m_nodes[43],m_nodes[42]);
        Field15->set_res_type(ResourceType::Wool);
        m_fields.push_back(Field15);

        const auto Field16 = new Field(16,5,m_nodes[33],m_nodes[34],m_nodes[35],m_nodes[46],m_nodes[45],m_nodes[44]);
        Field16->set_res_type(ResourceType::Wood);
        m_fields.push_back(Field16);

        //peti red
        const auto Field17 = new Field(17,6,m_nodes[39],m_nodes[40],m_nodes[41],m_nodes[49],m_nodes[48],m_nodes[47]);
        Field17->set_res_type(ResourceType::Wheat);
        m_fields.push_back(Field17);

        const auto Field18 = new Field(18,10,m_nodes[41],m_nodes[42],m_nodes[43],m_nodes[51],m_nodes[50],m_nodes[49]);
        Field18->set_res_type(ResourceType::Wheat);
        m_fields.push_back(Field18);

        //poslednje polje je pustinja pa cu staviti da je na njemu broj = 0,takodje nema tip resursa
        const auto Field19 = new Field(19,0,m_nodes[43],m_nodes[44],m_nodes[45],m_nodes[53],m_nodes[52],m_nodes[51]);
        m_fields.push_back(Field19);
}

