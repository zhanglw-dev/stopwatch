#ifndef CMDBTNSPLIT_H
#define CMDBTNSPLIT_H


#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include "swtimer.h"
#include "global.h"


using namespace std;

class SegmentButton : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    SegmentButton(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QRectF bindRectF;
    bool is_pressing;
    QWidget *_widget;

    SwTimer *swTimer;

public slots:
    void set_Enable();
    void set_Disable();
};


#endif // CMDBTNSPLIT_H
