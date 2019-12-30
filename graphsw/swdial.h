#ifndef DIAL_H
#define DIAL_H

#include <QPainter>
#include <QPoint>


class SwDial
{
public:
    SwDial(QPainter *painter, QPoint *point, int radius, QString name);
    virtual ~SwDial(){}

    void draw();
    void drawHand(int angle);

private:
    QPainter *painter;
    QPoint *point;
    int radius;
    QString name;
};


#endif // DIAL_H
