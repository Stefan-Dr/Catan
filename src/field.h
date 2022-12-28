#ifndef FIELD_H
#define FIELD_H
#include "resourcetype.h"
//#include "node.h"
//#include "road.h"
#include <QVector>

class Node;
class Road;


class Field
{
public:
    Field(int id, int number, ResourceType res_type,
          Node* up_corner, Node* bottom_corner,
          Node* bottom_right_corner, Node* bottom_left_corner,
          Node* up_right_corner, Node* up_left_corner,
          Road* right_edge, Road* left_edge,
          Road* bottom_right_edge, Road* bottom_left_edge,
          Road* up_right_edge, Road* up_left_edge);
    //probni konstruktor dok ne dodamo road-ove
    Field(int id, int number,
          Node* up_left_corner, Node* up_corner,
          Node* up_right_corner, Node* bottom_right_corner,
          Node* bottom_corner, Node* bottom_left_corner);
    Field(const Field&) = delete;

    int get_id() const;

    ResourceType get_res_type() const;

    int get_number() const;

    bool is_robber_on_the_field() const;

    QVector<Node*>& get_corners();

    const QVector<Road*>& get_edges() const;

    void set_robber_on_the_field(bool robber_on_the_field);

//getters for corners
    Node* get_up_corner() const;
    Node* get_down_corner() const;
    Node* get_bottom_right_corner() const;
    Node* get_bottom_left_corner() const;
    Node* get_up_right_corner() const;
    Node* get_up_left_conrer() const;

//getters for edges
    Road* get_right_edge() const;
    Road* get_left_edge() const;
    Road* get_bottom_right_edge() const;
    Road* get_bottom_left_edge() const;
    Road* get_up_right_edge() const;
    Road* get_up_left_edge() const;

 //res_type setter
    void set_res_type(ResourceType res_type);


private:
    int m_id;
    int m_number;
    ResourceType m_res_type;
    QVector<Node*>m_corners;
//parts of field for houses and cities
    Node* m_up_corner;
    Node* m_down_corner;
    Node* m_bottom_right_corner;
    Node* m_bottom_left_corner;
    Node* m_up_right_corner;
    Node* m_up_left_corner;
    QVector<Road*> m_edges;
//parts of field for roads
    Road* m_right_edge;
    Road* m_left_edge;
    Road* m_bottom_right_edge;
    Road* m_bottom_left_edge;
    Road* m_up_right_edge;
    Road* m_up_left_edge;
//variable for robber
    bool m_is_robber_od_the_field;
};

#endif // FIELD_H
