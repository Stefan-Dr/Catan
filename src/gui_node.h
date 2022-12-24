#ifndef GUI_NODE_H
#define GUI_NODE_H
#include "node.h"
#include <QPointF>
#include <QGraphicsObject>
#include <QBrush>
class Node;

class GUI_Node : public QGraphicsObject
{
    Q_OBJECT
public:
    GUI_Node(Node *node);


    // QGraphicsItem interface
    QRectF boundingRect() const override;
    QRectF position() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    inline void setBrush(QBrush b){m_brush = b;}
    inline const Node *Node_get() const {
        return m_node;
    }
    int type() const override;
    QPointF CenterPosition();
    Node *node() const;
    void setNode(Node *newNode);
    static QColor m_color;
signals:
    void nodeChanged();
    void needRedraw();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
private:
    Node *m_node;
 //   qreal m_x;
  //  qreal m_y;
    QBrush m_brush = QBrush(Qt::white);

    Q_PROPERTY(Node *node READ node WRITE setNode NOTIFY nodeChanged)
};

#endif // GUI_NODE_H
