#ifndef GUI_NODE_H
#define GUI_NODE_H

#include <QGraphicsObject>

class Node;

class GUI_Node : public QGraphicsObject
{
public:
    GUI_Node(Node *node);


    // QGraphicsItem interface
    QRectF boundingRect() const override;
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
    Q_PROPERTY(Node *node READ node WRITE setNode NOTIFY nodeChanged)
};

#endif // GUI_NODE_H
