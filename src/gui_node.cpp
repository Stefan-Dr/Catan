#include "gui_node.h"
#include <QPainter>
#include "node.h"
#include "qgraphicsscene.h"
#include "qgraphicssceneevent.h"
GUI_Node::GUI_Node(Node *node)
    : QGraphicsObject()
    , m_node(node)
{
    setFlags(GraphicsItemFlag::ItemIsSelectable | GraphicsItemFlag::ItemIsMovable);
    setAcceptHoverEvents(true);

}

QColor GUI_Node::m_color = QColor("white");

QRectF GUI_Node::boundingRect() const
{
    return QRectF(0,0,36,36);
}

QRectF GUI_Node::position() const{
    return QRectF(0,0,36,36);
}

void GUI_Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

//    painter->drawEllipse(boundingRect());
    if(m_brush!=QBrush(Qt::yellow))
        m_brush = QBrush(GUI_Node::m_color);
    painter->setBrush(m_brush);
    painter->drawEllipse(position());

}

void GUI_Node::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_brush = QBrush(Qt::yellow);
    emit needRedraw();
    QGraphicsObject::hoverEnterEvent(event);
}

void GUI_Node::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {

        m_brush = QBrush(GUI_Node::m_color);



    emit needRedraw();
    QGraphicsObject::hoverLeaveEvent(event);
}

QPointF GUI_Node::CenterPosition() {
    return pos() + QPointF(18, 18);
}


int GUI_Node::type() const{
    return 1;
}
