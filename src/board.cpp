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

    std::vector<QPointF> positions = {
        QPointF(185,55), QPointF(250,20), QPointF(315,55), QPointF(315,130),
        QPointF(250,165), QPointF(185,130), QPointF(380,20), QPointF(445,55),
        QPointF(445,130), QPointF(380,165), QPointF(510,20), QPointF(575,55),
        QPointF(575,130), QPointF(510,165), QPointF(120,165), QPointF(120,240),
        QPointF(185,270), QPointF(250,240), QPointF(315,270), QPointF(380,240),
        QPointF(445,270), QPointF(510,240), QPointF(575,270), QPointF(640,165),
        QPointF(640,240), QPointF(57,275), QPointF(57,350), QPointF(122,380),
        QPointF(187,350), QPointF(252,380), QPointF(317,350), QPointF(382,380),
        QPointF(447,350), QPointF(512,380), QPointF(577,350), QPointF(642,380),
        QPointF(707,350), QPointF(707,275), QPointF(122,460), QPointF(187,500),
        QPointF(252,460), QPointF(317,500), QPointF(382,460), QPointF(447,500),
        QPointF(512,460), QPointF(577,500), QPointF(642,460), QPointF(187,575),
        QPointF(250,600), QPointF(317,575), QPointF(380,600), QPointF(444,575),
        QPointF(510,600), QPointF(575,575)
    };
    std::vector<std::vector<int>> neighbours = {
        {2,6}, {1,3}, {2,4,7}, {3,5,10}, {4,6,18}, {1,5,15}, {3,8},
        {7,9,11}, {8,10,14}, {4,9,20}, {8,12}, {11,13}, {12,14,24}, {9,13,22},
        {6,16}, {15,17,26}, {16,18,29}, {5,17,19}, {18,20,31}, {10,19,21}, {20,22,33},
        {14,21,23}, {22,25,35}, {13,25}, {23,24,37}, {16,27}, {26,28}, {27,29,39},
        {17,28,30}, {29,31,41}, {19,30,32}, {31,33,43}, {21,32,34}, {33,35,45}, {23,34,36},
        {35,37,47}, {36,38}, {25,37}, {28,40}, {39,41}, {30,40,42}, {41,43,50}, {32,42,44},
        {43,45,52}, {34,44,46}, {45,47,54}, {36,46}, {40,49}, {48,50}, {42,49,51}, {50,52}, {44,51,53}, {52,54}, {46,53}
    };
    const int NODE_COUNT = 54;
    for (int node_id = 1; node_id <= NODE_COUNT; node_id++) {
        auto gui_node = new GUI_Node(positions[node_id - 1]);
        auto node = new Node(node_id, gui_node);
        node->set_all_neighbours(neighbours[node_id - 1]);
        m_nodes.push_back(node);
    }
    /*prvi heksagon prvi red */

    for(int i=0;i<54;i++)
          addItem(m_nodes[i]->get_gui_node());
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
        const auto Field4 = new Field(4,2,m_nodes[14],m_nodes[5],m_nodes[4], m_nodes[17], m_nodes[18], m_nodes[15]);
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

