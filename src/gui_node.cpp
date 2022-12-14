#include "gui_node.h"
#include <QPainter>
#include "node.h"

GUI_Node::GUI_Node(Node *node,QPointF p)
    : QGraphicsObject()
    , m_node(node)
    , m_x(p.rx())
    , m_y(p.ry())
{

}

QRectF GUI_Node::boundingRect() const
{
    return QRectF(0,0,36,36);
}

QRectF GUI_Node::position() const{
    return QRectF(m_x,m_y,36,36);
}

void GUI_Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

//    painter->drawEllipse(boundingRect());
    painter->drawEllipse(position());

}
