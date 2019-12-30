
#include "cmdbtnright.h"
#include "QWidget"
#include "QDebug"



CmdButtonRight::CmdButtonRight(SwButtonRight *swBtnRight, QGraphicsItem *parent):
    CmdButton(CMD_BUTTON_LOC_RIGHT, parent)
{
    this->swBtnRight = swBtnRight;
}


void CmdButtonRight::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Right CmdButton Event";
    this->onPress();
    swBtnRight->procMousePress();
}


void CmdButtonRight::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Right CmdButton release Event";
    this->onRelease();
    swBtnRight->procMouseRelease();
}
