#ifndef FIELD_H
#define FIELD_H
#include "resourcetype.h"
#include <QVector>

class Node;
class Road;


class Field
{
public:
    //konstruktor
    Field(int id, int number, ResourceType res_type,
          Node* up_corner, Node* bottom_corner,
          Node* bottom_right_corner, Node* bottom_left_corner,
          Node* up_right_corner, Node* up_left_corner,
          Road* right_edge, Road* left_edge,
          Road* bottom_right_edge, Road* bottom_left_edge,
          Road* up_right_edge, Road* up_left_edge);
    //konstruktor
    Field(int id, int number,
          Node* up_left_corner, Node* up_corner,
          Node* up_right_corner, Node* bottom_right_corner,
          Node* bottom_corner, Node* bottom_left_corner);
    Field(const Field&) = delete;

    //geteri
    int get_id() const;
    ResourceType get_res_type() const;
    int get_number() const;
    QVector<Node*>& get_corners();
    const QVector<Road*>& get_edges() const;
    Node* get_up_corner() const;
    Node* get_down_corner() const;
    Node* get_bottom_right_corner() const;
    Node* get_bottom_left_corner() const;
    Node* get_up_right_corner() const;
    Node* get_up_left_conrer() const;
    Road* get_right_edge() const;
    Road* get_left_edge() const;
    Road* get_bottom_right_edge() const;
    Road* get_bottom_left_edge() const;
    Road* get_up_right_edge() const;
    Road* get_up_left_edge() const;

    //seteri
    void set_res_type(ResourceType res_type);
    void set_robber_on_the_field(bool robber_on_the_field);

    bool is_robber_on_the_field() const;

private:

    int m_id;
    int m_number;
    ResourceType m_res_type;
    QVector<Node*>m_corners;

    Node* m_up_corner;
    Node* m_down_corner;
    Node* m_bottom_right_corner;
    Node* m_bottom_left_corner;
    Node* m_up_right_corner;
    Node* m_up_left_corner;
    QVector<Road*> m_edges;

    Road* m_right_edge;
    Road* m_left_edge;
    Road* m_bottom_right_edge;
    Road* m_bottom_left_edge;
    Road* m_up_right_edge;
    Road* m_up_left_edge;

    bool m_is_robber_od_the_field;
};

#endif // FIELD_H
