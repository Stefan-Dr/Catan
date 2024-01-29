#ifndef NODE_H
#define NODE_H
#include <QVector>

class Node {
 private:
  int m_id;
  bool m_is_house_built;
  bool m_is_city_built;
  int m_owner;
  bool m_can_build;
  bool m_can_build_city = false;
  QVector<int> m_neighbours;

 public:
  // constructor
  Node(int id);
  // destructor
  Node(const Node &) = delete;

  // Getters
  int get_id() const;
  bool get_is_house_built() const;
  bool get_is_city_built() const;
  int get_owner() const;
  bool get_can_build() const;
  bool get_can_build_city() const;
  const QVector<int> &get_neighbours() const;

  // Setters
  void set_is_house_built(bool value);
  void set_is_city_built(bool value);
  void set_owner(int owner);
  void set_can_build(bool value);
  void set_can_build_city(bool value);
  void set_all_neighbours(QVector<int> &neighbours);

  void place_house(int owner);
  void place_city(int owner);
};

#endif  // NODE_H
