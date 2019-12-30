#include "swbtn.h"
#include <QGraphicsEllipseItem>
#include <QPixmap>
#include <QWidget>
#include <QDebug>



SwButton::SwButton(SWatch *swatch, int angle, QGraphicsItem *parent):
    QGraphicsItem(parent)
{
    this->swatch = swatch;
    this->angle = angle;
    this->radius = swatch->getRadius();
    this->is_pressing = false;
    this->_widget = nullptr;
    setAcceptedMouseButtons(Qt::LeftButton);

    //topLeft = QPointF(-radius/6, -(radius+radius/6));
    //bottomRight = QPointF(topLeft.rx() + (radius/6)*2, topLeft.ry() + radius/6);

    //for android's bug, make enough size here, keep scale 1: >2!
    topLeft = QPointF(-5000, -5000);
    bottomRight = QPointF(5000, 20000);

    swTimer = SwTimer::getInstance();
    setRotation(angle);

    swState = SwState::getInstance();
}


QRectF SwButton::boundingRect() const
{
    /*
    qreal x = radius*sin(6.2832*35/360);
    qreal y = radius*cos(6.2832*35/360);
    //qDebug() << radius << " : " << x << " x " << y;

    if(place == LOCATE_BUTTON_LEFT){
        return QRectF(QPointF(-(x+radius/3), -(y+radius/3)), QPointF(-(x-radius/3), -(y-radius/3)));
    }else{
        return QRectF(QPointF((x-radius/3), -(y+radius/3)), QPointF((x+radius/3), -(y-radius/3)));
    }
    */

    return QRectF(topLeft, bottomRight);
}


QPainterPath SwButton::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}


void SwButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    _widget = widget;

    painter->setPen(QColor(0,0,0));   //bug fix for Android issues
    painter->save();

    this->radius = swatch->getRadius();

    if(is_pressing){
        topLeft = QPointF(-radius/5, -(radius + radius/10));
        bottomRight = QPointF(topLeft.rx() + (radius/5)*2, topLeft.ry() + radius/8);
    }
    else {
        topLeft = QPointF(-radius/5, -(radius+radius/5));
        bottomRight = QPointF(topLeft.rx() + (radius/5)*2, topLeft.ry() + radius/8);
    }

    QRectF rect(topLeft, bottomRight);

    QLinearGradient linearGrad(topLeft, bottomRight);

    if(angle < 0){  //LEFT
        linearGrad.setColorAt(0, QColor(190,0,0));
        linearGrad.setColorAt(0.3, QColor(200,0,0));
        linearGrad.setColorAt(0.5, QColor(220,0,0));
        linearGrad.setColorAt(1, QColor(130,0,0));
    }else{  //RIGHT
        linearGrad.setColorAt(0, QColor(140,199,0));
        linearGrad.setColorAt(0.3, QColor(180,225,0));
        linearGrad.setColorAt(1, QColor(113,160,0));
    }

    QPen pen;
    pen.setColor(QColor(255,255,255));
    painter->setPen(pen);
    painter->setBrush(linearGrad);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawRect(rect);
    painter->restore();
}


void SwButton::onPress()
{
    is_pressing = true;
    if(_widget)
        _widget->update();
}


void SwButton::onRelease()
{
    is_pressing = false;
    if(_widget)
        _widget->update();
}

