#ifndef WATCH_H
#define WATCH_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include "global.h"


class SWatch : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    SWatch(const QRectF &sceneRectF, QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getRadius(){ return radius; }

private:
    int radius;
    int width;
    int height;

    TimeCount timeCount;
    QWidget *_widget;

public slots:
    void updateCount(TimeCount &timeCount);
};

#endif // WATCH_H
