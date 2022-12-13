#include "gui_node.h"
#include <QPainter>
#include "node.h"

GUI_Node::GUI_Node(Node *node)
    : QGraphicsObject()
    , m_node(node)
{

}

QRectF GUI_Node::boundingRect() const
{
    return QRectF(188,55,36,36);
}

void GUI_Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawEllipse(boundingRect());
}
