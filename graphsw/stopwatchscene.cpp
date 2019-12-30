#include "stopwatchscene.h"
#include "swtimer.h"
#include "cmdbtnleft.h"



StopWatchScene::StopWatchScene(const QRectF &sceneRectF, QObject *parent):
    QGraphicsScene(sceneRectF, parent)
{
    swatch = new SWatch(sceneRectF);
    SwTimer::getInstance()->registWatch(swatch);
    this->addItem(swatch);

    swLeftButton = new SwButtonLeft(swatch);
    this->addItem(swLeftButton);

    swRightButton = new SwButtonRight(swatch);
    this->addItem(swRightButton);

    //segmentButton = new SegmentButton();
    //this->addItem(segmentButton);
    //SwTimer::getInstance()->registSegmtBtn(segmentButton);

    buttonLeft = new CmdButtonLeft(swLeftButton);
    this->addItem(buttonLeft);

    buttonRight = new CmdButtonRight(swRightButton);
    this->addItem(buttonRight);
}


StopWatchScene::~StopWatchScene()
{
    delete swatch;
    delete swLeftButton;
    delete swRightButton;
    delete buttonLeft;
    delete buttonRight;
    //delete segmentButton;
}
