#include "btnbase.h"
#include <QDebug>
#include <QPainter>


BtnBase::BtnBase(QWidget *parent, QColor color):
    QWidget(parent),color(color)
{
}


BtnBase::~BtnBase()
{

}


QSize BtnBase::sizeHint() const
{
    return QSize(100, 20);
}


void BtnBase::paintEvent(QPaintEvent *event)
{
    int w = width();
    int h = height();

    QRect rect(0, 0, w, h);

    //qDebug() << w << " " << h;
    QPainter painter(this);
    //QPen pen;
    //pen.setColor(Qt::red);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(rect);
}
