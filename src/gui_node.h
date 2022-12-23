#ifndef GUI_NODE_H
#define GUI_NODE_H
#include "node.h"
#include <QPointF>
#include <QGraphicsObject>

class Node;

class GUI_Node : public QGraphicsObject
{
public:
    GUI_Node(QPointF);


    // QGraphicsItem interface
    QRectF boundingRect() const override;
    QRectF position() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    inline const Node *Node_get() const {
        return m_node;
    }

    Node *node() const;
    void setNode(Node *newNode);

signals:
    void nodeChanged();

private:
    Node *m_node;
    qreal m_x;
    qreal m_y;
    Q_PROPERTY(Node *node READ node WRITE setNode NOTIFY nodeChanged)
};

#endif // GUI_NODE_H
