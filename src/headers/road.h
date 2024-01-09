#ifndef ROAD_H
#define ROAD_H
#include <iostream>

class Road {
public:
  // constructor
  Road(int owner, int id);
  // destructor
  Road(const Road &) = delete;

  // getters
  int get_owner() const;
  int get_id() const;
  bool get_can_build() const;

  // setters
  void set_owner(int owner);
  void set_can_build(bool value);

private:
  int m_owner;
  int m_id;
  bool m_can_build = false;
};

#endif // ROAD_H
