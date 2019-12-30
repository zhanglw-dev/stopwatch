#ifndef BUTTONLEFT_H
#define BUTTONLEFT_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include "cmdbtn.h"
#include "swbtnleft.h"



class CmdButtonLeft : public CmdButton
{
    Q_OBJECT
public:
    CmdButtonLeft(SwButtonLeft *swBtnLeft, QGraphicsItem *parent=nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    SwButtonLeft *swBtnLeft;
};


#endif // BUTTONLEFT_H
