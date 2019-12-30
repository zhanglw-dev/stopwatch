#include "cmdbtn.h"
#include <QDebug>


CmdButton::CmdButton(int loc, QGraphicsItem *parent):
    QGraphicsItem(parent)
{
    setAcceptedMouseButtons(Qt::LeftButton);
    this->loc = loc;
    this->is_pressing = false;
    this->_widget = nullptr;

    //for android's bug, make enough size here, keep scale 1: >2!
    bindRectF.setX(-5000);
    bindRectF.setY(-5000);
    bindRectF.setWidth(20000);
    bindRectF.setHeight(20000);
}


QRectF CmdButton::boundingRect() const
{
    return bindRectF;
}


QPainterPath CmdButton::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}


void CmdButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)

    this->_widget = widget;
    painter->setPen(QColor(0,0,0));   //bug fix for Android issues

    int w = widget->width();
    int h = widget->height();

    painter->save();

    /*
    if(loc == CMD_BUTTON_LOC_LEFT){
        if(is_pressing){
            bindRectF.setX(-w/3-w/10 + 6);
            bindRectF.setY((h/2) * 4/5 + 6);
            bindRectF.setWidth(w/3 -6*2);
            bindRectF.setHeight(h/16 - 6*2);
        }
        else{
            bindRectF.setX(-w/3-w/10);
            bindRectF.setY((h/2) * 4/5);
            bindRectF.setWidth(w/3);
            bindRectF.setHeight(h/16);
        }
    }
    else{
        if(is_pressing){
            bindRectF.setX(w/10 +6);
            bindRectF.setY((h/2) * 4/5 + 6);
            bindRectF.setWidth(w/3 - 6*2);
            bindRectF.setHeight(h/16 - 6*2);
        }
        else{
            bindRectF.setX(w/10);
            bindRectF.setY((h/2) * 4/5);
            bindRectF.setWidth(w/3);
            bindRectF.setHeight(h/16);
        }
    }
    */

    if(loc == CMD_BUTTON_LOC_LEFT){
        if(!is_pressing){
            bindRectF.setX(-w/6);
            bindRectF.setY(h/3 + w/7);
            bindRectF.setWidth(w/3);
            bindRectF.setHeight(w/9);
        }
        else{
            bindRectF.setX(-w/6 + w/30);
            bindRectF.setY(h/3 + w/7);
            bindRectF.setWidth(w/3 - w/15);
            bindRectF.setHeight(w/9);
        }
    }
    else{
        if(!is_pressing){
            bindRectF.setX(-w/6);
            bindRectF.setY(h/3);
            bindRectF.setWidth(w/3);
            bindRectF.setHeight(w/9);
        }
        else{
            bindRectF.setX(-w/6 + w/30);
            bindRectF.setY(h/3);
            bindRectF.setWidth(w/3 - w/15);
            bindRectF.setHeight(w/9);
        }
    }

    QPointF leftPointF(bindRectF.x(), bindRectF.y());
    QPointF rightPointF(bindRectF.x() + bindRectF.width(), bindRectF.y() + bindRectF.height());
    QLinearGradient linearGrad(leftPointF, rightPointF);
    if(loc == CMD_BUTTON_LOC_LEFT){
        linearGrad.setColorAt(0, QColor(190,0,0));
        linearGrad.setColorAt(0.3, QColor(200,0,0));
        linearGrad.setColorAt(0.5, QColor(220,0,0));
        linearGrad.setColorAt(1, QColor(190,0,0));
    }
    else{
        linearGrad.setColorAt(0, QColor(113,160,0));
        linearGrad.setColorAt(0.6, QColor(140,199,0));
        linearGrad.setColorAt(1, QColor(113,160,0));
    }

    QPen pen;
    pen.setColor(QColor(255,255,255));
    painter->setPen(pen);
    painter->setBrush(linearGrad);

    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawRoundedRect(bindRectF, h/60, h/60);
    //painter->drawEllipse(bindRectF);
    painter->restore();
}


void CmdButton::onPress()
{
    this->is_pressing = true;
    if(_widget)
        _widget->update();
}


void CmdButton::onRelease()
{
    this->is_pressing = false;
    if(_widget)
        _widget->update();
}

