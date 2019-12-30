#include "swbtnright.h"
#include <QDebug>


SwButtonRight::SwButtonRight(SWatch *swatch, QGraphicsItem *parent):
    SwButton(swatch, 39, parent)
{
}


void SwButtonRight::procMousePress()
{
    onPress();
    swState->onRight();
}


void SwButtonRight::procMouseRelease()
{
    onRelease();
}


void SwButtonRight::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Right press Event";
    procMousePress();
}


void SwButtonRight::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Right release Event";
    procMouseRelease();
}
