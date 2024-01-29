#include "../headers/gui_node.h"
#include "../headers/node.h"
#include "qgraphicsscene.h"
#include "qgraphicssceneevent.h"
#include <QPainter>

// constructor
GUI_Node::GUI_Node (Node *node) : QGraphicsObject (), m_node (node)
{
  setFlags (GraphicsItemFlag::ItemIsSelectable);
  setAcceptHoverEvents (true);
}

// getters
bool
GUI_Node::get_hasRoad () const
{
  return hasRoad;
}

bool
GUI_Node::get_is_city_built () const
{
  return m_is_city_built;
}

bool
GUI_Node::get_is_end_of_road () const
{
  return m_is_end_of_road;
}

Node *
GUI_Node::getNode () const
{
  return m_node;
}

bool
GUI_Node::get_is_house_built () const
{
  return m_is_house_built;
}

// setters
void
GUI_Node::set_is_end_of_road (bool value)
{
  m_is_end_of_road = value;
}

void
GUI_Node::set_is_city_built (bool value)
{
  m_is_city_built = value;
}

void
GUI_Node::set_hasRoad (bool x)
{
  hasRoad = x;
}

void
GUI_Node::setNode (Node *newNode)
{
  m_node = newNode;
}

void
GUI_Node::set_is_house_built (bool value)
{
  m_is_house_built = value;
}

QColor GUI_Node::m_color = QColor ("white");

QRectF
GUI_Node::boundingRect () const
{
  return QRectF (0, 0, 36, 36);
}

QRectF
GUI_Node::position () const
{
  return QRectF (0, 0, 36, 36);
}

void
GUI_Node::paint (QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
  Q_UNUSED (option)
  Q_UNUSED (widget)

  //    painter->drawEllipse(boundingRect());
  // if(m_brush!=QBrush(Qt::yellow))
  //  m_brush = QBrush(GUI_Node::m_color);
  painter->setBrush (m_brush);
  painter->drawEllipse (position ());

  if (m_brush == Qt::darkBlue || m_brush == Qt::darkGreen
      || m_brush == Qt::darkYellow || m_brush == Qt::darkRed)
    {
      const auto text = QString::fromStdString ("C");
      m_text = QString::fromStdString ("C");
      painter->setPen (Qt::white);
      painter->drawText (boundingRect (), Qt::AlignHCenter | Qt::AlignVCenter,
                         text);
    }

  else if (m_brush == Qt::blue || m_brush == Qt::green || m_brush == Qt::yellow
           || m_brush == Qt::red)
    {
      const auto text = QString::fromStdString ("H");
      m_text = QString::fromStdString ("H");
      painter->setPen (Qt::black);
      painter->drawText (boundingRect (), Qt::AlignHCenter | Qt::AlignVCenter,
                         text);
    }
}

void
GUI_Node::hoverEnterEvent (QGraphicsSceneHoverEvent *event)
{
  if (m_brush != Qt::green && m_brush != Qt::red && m_brush != Qt::yellow
      && m_brush != Qt::blue && m_brush != Qt::darkBlue
      && m_brush != Qt::darkGreen && m_brush != Qt::darkRed
      && m_brush != Qt::darkYellow)
    {
      m_brush = QBrush (Qt::gray);
    }

  emit needRedraw ();
  QGraphicsObject::hoverEnterEvent (event);
}

void
GUI_Node::hoverLeaveEvent (QGraphicsSceneHoverEvent *event)
{
  if (m_brush != Qt::green && m_brush != Qt::red && m_brush != Qt::yellow
      && m_brush != Qt::blue && m_brush != Qt::darkBlue
      && m_brush != Qt::darkGreen && m_brush != Qt::darkRed
      && m_brush != Qt::darkYellow)
    {
      m_brush = QBrush (GUI_Node::m_color);
    }

  emit needRedraw ();
  QGraphicsObject::hoverLeaveEvent (event);
}

QPointF
GUI_Node::CenterPosition ()
{
  return pos () + QPointF (18, 18);
}

bool
GUI_Node::check_owner_city (QColor color)
{
  if (getNode ()->get_owner () == 1 && color == Qt::darkBlue)
    return true;
  else if (getNode ()->get_owner () == 2 && color == Qt::darkYellow)
    return true;
  else if (getNode ()->get_owner () == 3 && color == Qt::darkGreen)
    return true;
  else if (getNode ()->get_owner () == 4 && color == Qt::darkRed)
    return true;
  else
    return false;
}

int
GUI_Node::type () const
{
  return 1;
}
