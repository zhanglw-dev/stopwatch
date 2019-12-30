#include "swtimer.h"
#include "swatch.h"
#include "__segmentbtn.h"
#include <QDebug>


static SwTimer *swTimer = nullptr;
QList<TimeCount> SwTimer::timeSegmtList;


SwTimer::SwTimer()
{
    resetCount();

    timer = new QTimer(this);
    timer->stop();
    timer->setInterval(10);
    msec_paused = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(on_timerTimeout()));
}


SwTimer* SwTimer::getInstance()
{
    if(!swTimer)
        swTimer = new SwTimer();
    return swTimer;
}


void SwTimer::start()
{
    time_start.restart();
    timer->start();
    emit enableSegmt();
}


void SwTimer::countrun()
{
    TimeCount timeCount = getTimeCount();
    if(SwTimer::timeSegmtList.size() == 12)
        SwTimer::timeSegmtList.pop_back();
    SwTimer::timeSegmtList.push_front(timeCount);
}


void SwTimer::resume()
{
    QTime time_resume;
    time_resume.start();
    msec_paused += time_last.msecsTo(time_resume);

    timer->start();
    //emit enableSegmt();
}


void SwTimer::pause()
{
    timer->stop();
    //emit disableSegmt();
}


void SwTimer::stop()
{
    msec_paused = 0;
    timer->stop();
    resetCount();
    SwTimer::timeSegmtList.clear();
    emit updateCount(timeCount);
    //emit disableSegmt();
}


void SwTimer::registWatch(SWatch *swatch)
{
    this->swatch = swatch;
    connect(this, SIGNAL(updateCount(TimeCount&)), swatch, SLOT(updateCount(TimeCount&)));
}


void SwTimer::registSegmtBtn(SegmentButton *segmtBtn)
{
    connect(this, SIGNAL(enableSegmt()), segmtBtn, SLOT(set_Enable()));
    connect(this, SIGNAL(disableSegmt()), segmtBtn, SLOT(set_Disable()));
}


void SwTimer::on_timerTimeout()
{
    doCount();
    emit updateCount(timeCount);
}


void SwTimer::resetCount()
{
    timeCount.hour = 0;
    timeCount.min = 0;
    timeCount.sec = 0;
    timeCount.msec10ths = 0;
}


void SwTimer::doCount()
{
    time_last.restart();
    int msec = time_start.msecsTo(time_last) - msec_paused;
    int msec10ths = (msec/10)%100;
    int sec = (msec/1000)%60;
    int min = ((msec/1000)/60)%60;
    int hour = ((msec/1000)/(60*60))%24;

    timeCount.msec10ths = msec10ths;
    timeCount.sec = sec;
    timeCount.min = min;
    timeCount.hour = hour;
}

