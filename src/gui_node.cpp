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

bool GUI_Node::get_hasRoad() const{
    return hasRoad;
}

void GUI_Node::set_hasRoad(bool x){
    hasRoad = x;
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
    //if(m_brush!=QBrush(Qt::yellow))
      //  m_brush = QBrush(GUI_Node::m_color);
    painter->setBrush(m_brush);
    painter->drawEllipse(position());

    if(m_brush == Qt::darkBlue || m_brush == Qt::darkGreen || m_brush == Qt::darkYellow || m_brush == Qt::darkRed){
        const auto text = QString::fromStdString("C");
        m_text = QString::fromStdString("C");
        painter->setPen(Qt::white);
        painter->drawText(boundingRect(), Qt::AlignHCenter | Qt::AlignVCenter, text);
    }

    else if(m_brush == Qt::blue || m_brush == Qt::green || m_brush == Qt::yellow || m_brush == Qt::red){
        const auto text = QString::fromStdString("H");
        m_text = QString::fromStdString("H");
        painter->setPen(Qt::black);
        painter->drawText(boundingRect(), Qt::AlignHCenter | Qt::AlignVCenter, text);
    }
}

void GUI_Node::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    if(m_brush != Qt::green && m_brush != Qt::red && m_brush != Qt::yellow && m_brush != Qt::blue && m_brush != Qt::darkBlue && m_brush != Qt::darkGreen && m_brush != Qt::darkRed && m_brush != Qt::darkYellow){
    m_brush = QBrush(Qt::gray);
    }

    emit needRedraw();
    QGraphicsObject::hoverEnterEvent(event);
}

void GUI_Node::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
     if(m_brush != Qt::green && m_brush != Qt::red && m_brush != Qt::yellow && m_brush != Qt::blue && m_brush != Qt::darkBlue && m_brush != Qt::darkGreen && m_brush != Qt::darkRed && m_brush != Qt::darkYellow){
      m_brush = QBrush(GUI_Node::m_color);



      }

     emit needRedraw();
     QGraphicsObject::hoverLeaveEvent(event);

}


QPointF GUI_Node::CenterPosition() {
    return pos() + QPointF(18, 18);
}

Node* GUI_Node::getNode()
{
    return m_node;
}

bool GUI_Node::get_is_house_built() const
{
    return m_is_house_built;
}

void GUI_Node::set_is_house_built(bool value)
{
    m_is_house_built = true;
}

bool GUI_Node::check_owner_city(QColor color)
{
    if (getNode()->get_owner() == 1 && color == Qt::darkBlue ) return true;
    else if (getNode()->get_owner() == 2 && color == Qt::darkYellow ) return true;
    else if (getNode()->get_owner() == 3 && color == Qt::darkGreen ) return true;
    else if (getNode()->get_owner() == 4 && color == Qt::darkRed ) return true;
    else return false;
}


int GUI_Node::type() const{
    return 1;
}


