#ifndef BUTTONITEM_H
#define BUTTONITEM_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QWidget>
#include "swtimer.h"
#include "swstate.h"
#include "swatch.h"


class SwButton : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    SwButton(SWatch *swatch, int angle, QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    SwTimer *swTimer;
    SwState *swState;
    void onPress();
    void onRelease();

private:
    SWatch *swatch;
    int angle;
    int radius;
    bool is_pressing;

    QPointF topLeft;
    QPointF bottomRight;

    QWidget *_widget;
};


#endif // BUTTONITEM_H
