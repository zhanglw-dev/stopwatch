#include "swdial.h"
#include <QDebug>


SwDial::SwDial(QPainter *painter, QPoint *point, int radius, QString name)
{
    this->painter = painter;
    this->point = point;
    this->radius = radius;
    this->name = name;
}


void SwDial::drawHand(int angle)
{
    painter->save();
    int x = point->x();
    int y = point->y();
    painter->translate(x, y);
    painter->rotate(angle);

    int w, h;

    w = radius/20>2 ? radius/20 : 2;
    h = radius/20>2 ? radius/20 : 2;
    painter->drawEllipse(QPoint(0, 0), w, h);

    w = radius/25;
    h = radius*9/10;
    painter->drawRect(-w/2, -radius*4/5, w, h);
    painter->drawRect(-w/2, -radius*4/5+h, w, radius*1/6);

    painter->restore();
}


void SwDial::draw()
{
    painter->save();
    //painter->drawEllipse(*point, radius, radius);
    int x = point->x();
    int y = point->y();
    painter->translate(x, y);

    int w, h;

    for (int i=0; i<60; i++){
        painter->rotate(360/60);

        QPen pen;
        pen.setWidth(1);
        pen.setColor(QColor(0, 0, 0));
        pen.setStyle(Qt::SolidLine);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(QColor(0, 0, 0));
        brush.setStyle(Qt::SolidPattern);
        painter->setBrush(brush);
        w = radius/80>1 ? radius/80 : 1;
        h = radius/35>1 ? radius/35 : 1;
        painter->drawRect(0, -radius, w, h);
    }

    for (int i=0; i<12; i++){
        painter->rotate(360/12);

        QPen pen;
        pen.setWidth(1);
        pen.setColor(QColor(0, 0, 0));
        pen.setStyle(Qt::SolidLine);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(QColor(0, 0, 0));
        brush.setStyle(Qt::SolidPattern);
        painter->setBrush(brush);

        w = radius/80>2 ? radius/80 : 2;
        h = radius/15>5 ? radius/15 : 5;
        painter->drawRect(0, -radius, w, h);
    }

    painter->restore();
}
