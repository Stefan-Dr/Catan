#ifndef GUI_NODE_H
#define GUI_NODE_H
#include "node.h"
#include <QBrush>
#include <QGraphicsObject>
#include <QPointF>
class Node;

class GUI_Node : public QGraphicsObject
{
  Q_OBJECT
public:
  GUI_Node(Node* node);
  ~GUI_Node();

  // QGraphicsItem interface
  QRectF boundingRect() const override;
  QRectF position() const;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  inline void setBrush(QBrush b) { m_brush = b; }
  inline const Node* Node_get() const { return m_node; }
  inline QBrush getBrush() { return m_brush; }
  int type() const override;
  QPointF CenterPosition();

  void setNode(Node* newNode);
  Node* getNode() const;
  static QColor m_color;

  bool get_is_house_built() const;
  void set_is_house_built(bool value);
  QString m_text = QString::fromStdString("");
  bool check_owner_city(QColor color);

  bool get_hasRoad() const;
  void set_hasRoad(bool x);

  bool get_is_end_of_road() const;
  void set_is_end_of_road(bool value);

  bool get_is_city_built() const;
  void set_is_city_built(bool value);

signals:
  void nodeChanged();
  void needRedraw();

protected:
  void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
  Node* m_node;
  bool hasRoad;

  QBrush m_brush = QBrush(Qt::white);
  Q_PROPERTY(Node* node READ getNode WRITE setNode NOTIFY nodeChanged)
  bool m_is_house_built = false;
  bool m_is_end_of_road = false;
  bool m_is_city_built = false;
};

#endif // GUI_NODE_H
