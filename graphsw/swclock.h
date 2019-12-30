#ifndef SWCLOCK_H
#define SWCLOCK_H

#include <QPainter>
#include <QPoint>


class SwClock
{
public:
    SwClock(QPainter *painter, QPoint *point, int radius);
    virtual ~SwClock(){}
    void draw(int min, int sec, int n10ths);

private:
    QPainter *painter;
    QPoint *point;
    int radius;

    int digit_spl_1 = radius/30;
    int digit_spl_2 = radius/12;
    int digit_w = radius/9;
    int digit_h = radius/7;

    void drawDigit(int x, int y, bool is_red, int num);
};


#endif // SWCLOCK_H
