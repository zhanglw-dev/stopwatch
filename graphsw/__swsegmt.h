#ifndef SWSEGMENT_H
#define SWSEGMENT_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include "swtimer.h"
#include "global.h"


using namespace std;


class SwSegment : public QObject
{
    Q_OBJECT
public:
    SwSegment(QPainter *painter, QPoint *point, int radius);
    virtual ~SwSegment(){}

    void draw();

private:
    QPainter *painter;
    QPoint *point;
    int radius;
};


#endif // SWSEGMENT_H
