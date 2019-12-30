#include <QGraphicsEllipseItem>
#include <QPixmap>
#include <QWidget>
#include <QDebug>
#include "swatch.h"
#include "swdial.h"
#include "swclock.h"
#include "__swsegmt.h"


SWatch::SWatch(const QRectF &sceneRectF, QGraphicsItem *parent):
    QGraphicsItem(parent)
{
    radius = qMin(sceneRectF.toRect().width(), sceneRectF.toRect().height())/3;
    timeCount.min = 0;
    timeCount.sec = 0;
    timeCount.msec10ths = 0;
    _widget = nullptr;
}


QRectF SWatch::boundingRect() const
{
    return QRectF(-radius, -radius, radius, radius);
}


void SWatch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    _widget = widget;

    /*
    //paint backgroud
    painter->save();
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    QRect rct = widget->rect();
    //qDebug() << " " << rct.x() << " " << rct.y() << " " << widget->width() << " " << widget->height();
    painter->drawRect(-rct.width(), -rct.height(), rct.width()*2, rct.height()*2);
    painter->restore();
    */

    width = widget->width();
    height = widget->height();

    painter->save();
    QPen pen;
    pen.setColor(QColor(255,255,255));
    painter->setPen(pen);

    QLinearGradient linearGrad(QPointF(-width/2, -height/2), QPointF(width/2, height/2));
    linearGrad.setColorAt(0, QColor(192,186,186));
    linearGrad.setColorAt(0.6, QColor(246,243,243));
    linearGrad.setColorAt(1, QColor(190,180,180));

    painter->setBrush(linearGrad);
    painter->drawRect(QRect(-width/2, -height/2, width*2, height*2));

    painter->restore();


    radius = static_cast<int>(qMin(width, height)/2.5);

    //painter->setViewTransformEnabled(false);
    painter->setPen(QColor(0,0,0));   //bug fix for Android issues
    painter->setRenderHints(QPainter::Antialiasing, true);

    QPoint point(0, 0);
    SwDial dialMain(painter, &point, radius*17/20, "xxx");
    dialMain.draw();
    dialMain.drawHand(timeCount.sec * 6);

    QPoint pointDialLeft(-radius/3, -radius/3);
    SwDial dialLeft(painter, &pointDialLeft, radius/4, "xxx");
    dialLeft.draw();
    dialLeft.drawHand(timeCount.min * 6);

    QPoint pointDialRight(radius/3, -radius/3);
    SwDial dialRight(painter, &pointDialRight, radius/4, "xxx");
    dialRight.draw();
    dialRight.drawHand(int(timeCount.msec10ths * 3.6));

    QPoint pointClock(0, radius*3/8);
    SwClock clock(painter, &pointClock, radius);
    clock.draw(timeCount.min, timeCount.sec, timeCount.msec10ths);

    SwSegment segmt(painter, &point, radius);
    segmt.draw();
}


void SWatch::updateCount(TimeCount &timeCount)
{
    this->timeCount = timeCount;
    if(_widget)
        _widget->update();
}

