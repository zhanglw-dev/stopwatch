
#include "cmdbtnleft.h"
#include "QWidget"
#include "QDebug"



CmdButtonLeft::CmdButtonLeft(SwButtonLeft *swBtnLeft, QGraphicsItem *parent):
    CmdButton(CMD_BUTTON_LOC_LEFT, parent)
{
    this->swBtnLeft = swBtnLeft;
}


void CmdButtonLeft::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Left CmdButton Event";
    this->onPress();
    swBtnLeft->procMousePress();
}


void CmdButtonLeft::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Left CmdButton release Event";
    this->onRelease();
    swBtnLeft->procMouseRelease();
}
