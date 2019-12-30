#ifndef STOPWATCHSCENE_H
#define STOPWATCHSCENE_H

#include <QGraphicsScene>
#include "swatch.h"
#include "swbtnleft.h"
#include "swbtnright.h"
#include "cmdbtnleft.h"
#include "cmdbtnright.h"
//#include "segmentbtn.h"


class StopWatchScene:public QGraphicsScene
{
    Q_OBJECT

public:
    explicit StopWatchScene(const QRectF &sceneRectF, QObject *parent=nullptr);
    virtual ~StopWatchScene();

private:
    StopWatchScene(qreal x, qreal y, qreal width, qreal height, QObject *parent=nullptr):QGraphicsScene(x, y, width, height, parent){}
    StopWatchScene(QObject *parent = nullptr):QGraphicsScene(parent){}

    SWatch *swatch;
    SwButtonLeft *swLeftButton;
    SwButtonRight *swRightButton;
    CmdButtonLeft *buttonLeft;
    CmdButtonRight *buttonRight;
    //SegmentButton *segmentButton;
};


#endif // STOPWATCHSCENE_H
