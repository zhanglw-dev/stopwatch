#include "digitled.h"
#include <QDebug>
#include <QPainter>



DigitLED::DigitLED(QWidget *parent):
    QWidget(parent)
{

}


DigitLED::~DigitLED()
{

}


QSize DigitLED::sizeHint() const
{
    return QSize(100, 120);
}


void DigitLED::paintEvent(QPaintEvent *event)
{
    int w = width();
    int h = height();

    //qDebug() << w << " " << h;

    QRect rect(0, 0, w, h);

    //qDebug() << w << " " << h;
    QPainter painter(this);
    //QPen pen;
    //pen.setColor(Qt::red);
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(rect);
}
