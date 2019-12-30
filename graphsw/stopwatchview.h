#ifndef STOPWATCHVIEW_H
#define STOPWATCHVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include <QTime>


class StopWatchView : public QGraphicsView
{
    Q_OBJECT

public:
    StopWatchView(QGraphicsScene *scene, QWidget *parent = nullptr);
    virtual ~StopWatchView(){}

private:
    StopWatchView(QWidget *parent = nullptr):QGraphicsView(parent){}
};

#endif // STOPWATCHVIEW_H
