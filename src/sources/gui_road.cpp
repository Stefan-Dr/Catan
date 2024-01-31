#include "../headers/gui_road.h"

#include <QPainter>
#include <QtMath>
#include <climits>
#include <cmath>

// constructor
GUI_Road::GUI_Road(GUI_Node *start, GUI_Node *end)
    : QGraphicsLineItem(), m_start(start), m_end(end) {}

GUI_Road::~GUI_Road() = default;

QColor GUI_Road::m_color = QColor("blue");

QRectF GUI_Road::boundingRect() const {
  QPainterPath ret;
  QPolygonF nPolygon;
  auto line = QLineF(m_start->CenterPosition(), m_end->CenterPosition());
  qreal radAngle = line.angle() * M_PI / 180;
  qreal dx = sin(radAngle);
  qreal dy = cos(radAngle);
  QPointF offset1;
  QPointF offset2;

  dx *= 40;
  dy *= 40;
  offset1 = QPointF(-dx, -dy);
  offset2 = QPointF(0, 0);
  nPolygon << line.p1() + offset1 << line.p1() + offset2 << line.p2() + offset2
           << line.p2() + offset1;
  return nPolygon.boundingRect();
}

// getters
QPointF GUI_Road::getCenter() {
  return QPointF(
      m_start->CenterPosition().rx() -
          (m_start->CenterPosition().rx() - m_end->CenterPosition().rx()) / 2.0,
      m_start->CenterPosition().ry() -
          (m_start->CenterPosition().ry() - m_end->CenterPosition().ry()) /
              2.0);
}

// setters
void GUI_Road::set_pen(QColor color) { m_pen = QPen(color); }

void GUI_Road::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->setPen(m_pen);
  m_pen.setWidth(10);
  painter->drawLine(m_start->CenterPosition(), m_end->CenterPosition());
}
