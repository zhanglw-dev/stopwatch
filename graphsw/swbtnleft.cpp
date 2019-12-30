#include "swbtnleft.h"
#include <QDebug>


SwButtonLeft::SwButtonLeft(SWatch *swatch, QGraphicsItem *parent):
    SwButton(swatch, -39, parent)
{
}


void SwButtonLeft::procMousePress()
{
    onPress();
    swState->onLeft();
}


void SwButtonLeft::procMouseRelease()
{
     onRelease();
}


void SwButtonLeft::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Left press Event";
    procMousePress();
}


void SwButtonLeft::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Left release Event";
    procMouseRelease();
}
