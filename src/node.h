#ifndef NODE_H
#define NODE_H
#include <QVector>

class Node
{
private:
    //id of the node
    int m_id;
    bool m_is_house_built;
    bool m_is_city_built;
    //id of player who has a house or a city on the node
    int m_owner;
    //indicator if the node meets requirements for building
    bool m_can_build;
    bool m_can_build_city = false;
    QVector<int> m_neighbours;



public:
    Node(int id);
    Node(const Node &) = delete;

    //Getters
    int get_id() const;
    bool get_is_house_built() const;
    bool get_is_city_built() const;
    int get_owner() const;
    bool get_can_build() const;
    bool get_can_build_city() const;
    const QVector<int>& get_neighbours() const;


    //Setters
    void set_is_house_built(bool value);
    void set_is_city_built(bool value);
    void set_owner(int owner);
    void set_can_build(bool value);
    void set_can_build_city(bool value);
    void set_all_neighbours(QVector<int> &neighbours);


    //Methods for setting a house or city on the node using setters
    void place_house(int owner);
    void place_city(int owner);

    //Methods for implementing qeuivalence possibly required
    //void operator==(Node &other) const;
    //void operator!=(Node &other) const;

};

#endif // NODE_H
