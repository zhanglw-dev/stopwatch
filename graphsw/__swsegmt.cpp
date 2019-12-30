#include "__swsegmt.h"
#include "global.h"
#include <QDebug>


SwSegment::SwSegment(QPainter *painter, QPoint *point, int radius)
{
    this->painter = painter;
    this->point = point;
    this->radius = radius;
}


void SwSegment::draw()
{
    painter->save();

    if(!SwTimer::timeSegmtList.empty())
    {
        QList<TimeCount>::iterator iter;

        QFont font;
        font.setPixelSize(radius/11);
        font.setBold(true);
        painter->setFont(font);

        for (iter=SwTimer::timeSegmtList.begin(); iter!=SwTimer::timeSegmtList.end(); ++iter)
        {
            TimeCount timeCount = *iter;
            int min_1 = timeCount.min/10;
            int min_2 = timeCount.min%10;
            int sec_1 = timeCount.sec/10;
            int sec_2 = timeCount.sec%10;
            int n10ths_1 = timeCount.msec10ths/10;
            int n10ths_2 = timeCount.msec10ths%10;

            QString text = QString("%1%2:%3%4:%5%6").arg(min_1).arg(min_2).arg(sec_1).arg(sec_2).arg(n10ths_1).arg(n10ths_2);

            int pos_x = -radius/4;
            int pos_y = -(radius);
            QRect rect_text(pos_x, pos_y, radius/2, radius/8);
            //painter->drawRect(rect_text);
            painter->drawText(rect_text, Qt::AlignCenter, text);

            painter->rotate(360/12);
        }
    }

    painter->restore();
}



