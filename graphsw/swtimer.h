#ifndef SWTIMER_H
#define SWTIMER_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include "global.h"
#include "swatch.h"


class SWatch;
class SegmentButton;


class SwTimer : public QObject
{
    Q_OBJECT
public:
    static SwTimer* getInstance();
    virtual ~SwTimer(){}

    void start();
    void countrun();
    void pause();
    void resume();
    void stop();

    void registWatch(SWatch *swatch);
    void registSegmtBtn(SegmentButton *segmtBtn);

    TimeCount getTimeCount(){ return timeCount; }

    static QList<TimeCount> timeSegmtList;

private:
    SwTimer();
    QTimer *timer;
    QTime time_start;
    QTime time_last;
    int msec_paused;

    TimeCount timeCount;
    void resetCount();
    void doCount();

    SWatch *swatch;

private slots:
    void on_timerTimeout();

signals:
    void updateCount(TimeCount &timeCount);
    void enableSegmt();
    void disableSegmt();
};


#endif // SWTIMER_H
