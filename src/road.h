#ifndef ROAD_H
#define ROAD_H
#include<iostream>

class Road
{
public:
    Road(int owner,int id);
    Road(const Road&) = delete;

    int get_owner() const;
    int get_id() const;
    void set_owner(int owner);
private:
    int m_owner;
    int m_id;
};

#endif // ROAD_H
