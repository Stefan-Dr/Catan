#include "../headers/field.h"

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

//destructor
Field::~Field()= default;
//getters
auto Field::get_id() const -> int{
    return m_id;
}

auto Field::get_number() const -> int{
    return m_number;
}

auto Field::get_res_type() const -> ResourceType{
    return m_res_type;
}


auto Field::get_corners() -> QVector<Node*>&{
    return m_corners;
}

auto Field::get_edges() const -> const QVector<Road*>&{
    return m_edges;
}

auto Field::get_up_corner() const -> Node*{
    return m_up_corner;
}

auto Field::get_down_corner() const -> Node*{
    return m_down_corner;
}

auto Field::get_bottom_right_corner() const -> Node*{
    return m_bottom_right_corner;
}

auto Field::get_bottom_left_corner() const -> Node*{
    return m_bottom_left_corner;
}

auto Field::get_up_right_corner() const -> Node*{
    return m_up_right_corner;
}

auto Field::get_up_left_conrer() const -> Node*{
    return m_up_left_corner;
}

auto Field::get_right_edge() const -> Road*{
    return m_right_edge;
}

auto Field::get_left_edge() const -> Road*{
    return m_left_edge;
}

auto Field::get_bottom_right_edge() const -> Road*{
    return m_bottom_right_edge;
}

auto Field::get_bottom_left_edge() const -> Road*{
    return m_bottom_left_edge;
}

auto Field::get_up_right_edge() const -> Road*{
    return m_up_right_edge;
}

auto Field::get_up_left_edge() const -> Road*{
    return m_up_left_edge;
}


auto Field::is_robber_on_the_field() const -> bool{
    return m_is_robber_od_the_field;
}

//setters
void Field::set_robber_on_the_field(bool robber_on_the_field){
    //moze samo m_is_robber_on_the_field = true;
    m_is_robber_od_the_field = robber_on_the_field;
}



void Field::set_res_type(ResourceType res_type){
    m_res_type = res_type;
}
