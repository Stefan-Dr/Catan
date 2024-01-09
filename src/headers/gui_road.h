#ifndef GUI_ROAD_H
#define GUI_ROAD_H

#include "gui_node.h"
#include <QGraphicsLineItem>
#include <QPen>
#include <QPolygon>

class GUI_Road : public QObject, public QGraphicsLineItem {
  Q_OBJECT
public:
  GUI_Road(GUI_Node *start, GUI_Node *end);
  ~GUI_Road();
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  static QColor m_color;
  GUI_Node *getStart() { return m_start; }
  GUI_Node *getEnd() { return m_end; }
  QPointF getCenter();
  void set_pen(QColor color);

signals:
  void needRedraw();

private:
  GUI_Node *m_start;
  GUI_Node *m_end;
  QPen m_pen = QPen(Qt::blue);
};

#endif // GUI_ROAD_H
