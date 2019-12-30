#ifndef CMDBTNRIGHT_H
#define CMDBTNRIGHT_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include "cmdbtn.h"
#include "swbtnright.h"



class CmdButtonRight : public CmdButton
{
    Q_OBJECT
public:
    CmdButtonRight(SwButtonRight *swBtnRight, QGraphicsItem *parent=nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    SwButtonRight *swBtnRight;
};


#endif // CMDBTNRIGHT_H
