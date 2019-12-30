#include "swclock.h"
#include <QDebug>


SwClock::SwClock(QPainter *painter, QPoint *point, int radius)
{
    this->painter = painter;
    this->point = point;
    this->radius = radius;

    digit_spl_1 = radius/50;
    digit_spl_2 = radius/20;
    digit_w = radius/9;
    digit_h = radius/7;
}


void SwClock::draw(int min, int sec, int n10ths)
{
    int min_1 = min/10;
    int min_2 = min%10;
    int sec_1 = sec/10;
    int sec_2 = sec%10;
    int n10ths_1 = n10ths/10;
    int n10ths_2 = n10ths%10;

    //painter->save();

    int x, y;
    //minute1
    x = point->x() - digit_w*3 - digit_spl_1*2 - digit_spl_2;
    y = point->y();
    drawDigit(x, y, false, min_1);

    //minute2
    x = point->x() - digit_w*2 - digit_spl_1 - digit_spl_2;
    y = point->y();
    drawDigit(x, y, false, min_2);

    //second1
    x = point->x() - digit_w - digit_spl_1;
    y = point->y();
    drawDigit(x, y, false, sec_1);

    //second2
    x = point->x();
    y = point->y();
    drawDigit(x, y, false, sec_2);

    //10ths1
    x = point->x() + digit_spl_1 + digit_w + digit_spl_2;
    y = point->y();
    drawDigit(x, y, false, n10ths_1);

    //10ths2
    x = point->x() + digit_spl_1*2 + digit_w*2 + digit_spl_2;
    y = point->y();
    drawDigit(x, y, false, n10ths_2);

    //painter->restore();
}


void SwClock::drawDigit(int x, int y, bool is_red, int num)
{
    QPoint point(x, y);
    QFont font;
    font.setPixelSize(radius/7);
    font.setBold(true);
    painter->setFont(font);
    QRect rect_h1_x(x, y, digit_w, digit_h);
    painter->drawRect(rect_h1_x);
    painter->drawText(rect_h1_x, Qt::AlignCenter,QString::number(num));
}
