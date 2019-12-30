#include "__segmentbtn.h"
#include "__swsegmt.h"
#include "swtimer.h"
#include <QDebug>


SegmentButton::SegmentButton(QGraphicsItem *parent):
    QGraphicsItem(parent)
{
    setAcceptedMouseButtons(Qt::LeftButton);
    this->is_pressing = false;
    this->_widget = nullptr;

    //for android's bug, make enough size here, keep scale 1: >2!
    bindRectF.setX(-5000);
    bindRectF.setY(-5000);
    bindRectF.setWidth(20000);
    bindRectF.setHeight(20000);

    this->swTimer = SwTimer::getInstance();
    //this->setEnabled(false);
}


QRectF SegmentButton::boundingRect() const
{
    return bindRectF;
}


QPainterPath SegmentButton::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}


void SegmentButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)

    this->_widget = widget;
    painter->setPen(QColor(0,0,0));   //bug fix for Android issues

    painter->save();

    int w = widget->width();
    int h = widget->height();

    if(!is_pressing){
        bindRectF.setX(-w/4);
        bindRectF.setY(h/3 - h/50);
        bindRectF.setWidth(w/2);
        bindRectF.setHeight(w/3);
    }
    else{
        bindRectF.setX(-w/12 + 6);
        bindRectF.setY(h/3 - h/10 + 6);
        bindRectF.setWidth(w/6 - 12);
        bindRectF.setHeight(w/6 - 12);
    }

    QPen pen;
    pen.setColor(QColor(255,255,255));
    painter->setPen(pen);

    QRadialGradient radialGrad(0, bindRectF.y()+bindRectF.height()/2, bindRectF.width()/2, 0, bindRectF.y()+bindRectF.height()/2);
    radialGrad.setColorAt(0, QColor(55, 51, 217));
    radialGrad.setColorAt(1, QColor(117, 115, 228));
    radialGrad.setSpread(QGradient::PadSpread);
    painter->setBrush(radialGrad);

    painter->drawEllipse(bindRectF);
    painter->restore();
}


void SegmentButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    TimeCount timeCount = swTimer->getTimeCount();
    if(SwTimer::timeSegmtList.size() == 12)
        SwTimer::timeSegmtList.pop_back();
    SwTimer::timeSegmtList.push_front(timeCount);

    this->is_pressing = true;
    if(_widget)
        _widget->update();
}


void SegmentButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->is_pressing = false;
    if(_widget)
        _widget->update();
}


void SegmentButton::set_Enable()
{
    qDebug() << "setEnable";
    this->setEnabled(true);
}


void SegmentButton::set_Disable()
{
    qDebug() << "setDisable";
    this->setEnabled(false);
}

