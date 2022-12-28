#include "field.h"

Field::Field(int id, int number, ResourceType res_type,
            Node* up_corner, Node* bottom_corner,
            Node* bottom_right_corner, Node* bottom_left_corner,
            Node* up_right_corner, Node* up_left_corner,
            Road* right_edge, Road* left_edge,
            Road* bottom_right_edge, Road* bottom_left_edge,
            Road* up_right_edge, Road* up_left_edge)
      :m_id(id), m_number(number), m_res_type(res_type),m_up_corner(up_corner),
      m_down_corner(bottom_corner),m_bottom_right_corner(bottom_right_corner),
      m_bottom_left_corner(bottom_left_corner),m_up_right_corner(up_right_corner),
      m_up_left_corner(up_left_corner),m_right_edge(right_edge),m_left_edge(left_edge),
      m_bottom_right_edge(bottom_right_edge),m_bottom_left_edge(bottom_left_edge),m_up_right_edge(up_right_edge),
      m_up_left_edge(up_left_edge),m_is_robber_od_the_field(false)
        {
            //inserting edges and corners into specialized vectors
            m_corners = {m_up_corner,m_up_left_corner,m_bottom_left_corner,
                        m_down_corner,m_bottom_right_corner, m_up_right_corner};
            m_edges = {m_up_left_edge,m_left_edge,m_bottom_left_edge,m_bottom_right_edge,
                    m_right_edge,m_up_right_edge};
        }

Field::Field(int id, int number,
             Node* up_left_corner, Node* up_corner,
             Node* up_right_corner, Node* bottom_right_corner,
             Node* bottom_corner, Node* bottom_left_corner)
    :m_id(id), m_number(number),m_up_corner(up_corner),
    m_down_corner(bottom_corner),m_bottom_right_corner(bottom_right_corner),
    m_bottom_left_corner(bottom_left_corner),m_up_right_corner(up_right_corner),
    m_up_left_corner(up_left_corner)
    {
    //inserting edges and corners into specialized vectors
            m_corners = {m_up_corner,m_up_left_corner,m_bottom_left_corner,
                         m_down_corner,m_bottom_right_corner, m_up_right_corner};
    }

int Field::get_id() const{
    return m_id;
}

int Field::get_number() const{
    return m_number;
}

ResourceType Field::get_res_type() const{
    return m_res_type;
}

bool Field::is_robber_on_the_field() const{
    return m_is_robber_od_the_field;
}

QVector<Node*>& Field::get_corners(){
    return m_corners;
}

const QVector<Road*>& Field::get_edges() const{
    return m_edges;
}

void Field::set_robber_on_the_field(bool robber_on_the_field){
    //moze samo m_is_robber_on_the_field = true;
    m_is_robber_od_the_field = robber_on_the_field;
}

Node* Field::get_up_corner() const{
    return m_up_corner;
}

Node* Field::get_down_corner() const{
    return m_down_corner;
}

Node* Field::get_bottom_right_corner() const{
    return m_bottom_right_corner;
}

Node* Field::get_bottom_left_corner() const{
    return m_bottom_left_corner;
}

Node* Field::get_up_right_corner() const{
    return m_up_right_corner;
}

Node* Field::get_up_left_conrer() const{
    return m_up_left_corner;
}

Road* Field::get_right_edge() const{
    return m_right_edge;
}

Road* Field::get_left_edge() const{
    return m_left_edge;
}

Road* Field::get_bottom_right_edge() const{
    return m_bottom_right_edge;
}

Road* Field::get_bottom_left_edge() const{
    return m_bottom_left_edge;
}

Road* Field::get_up_right_edge() const{
    return m_up_right_edge;
}

Road* Field::get_up_left_edge() const{
    return m_up_left_edge;
}

void Field::set_res_type(ResourceType res_type){
    m_res_type = res_type;
}
