#ifndef SWSTATE_H
#define SWSTATE_H

#include <QObject>
#include <QState>
#include <QStateMachine>
#include "swtimer.h"


class SwState : public QObject
{
    Q_OBJECT
public:
    static SwState* getInstance();
    virtual ~SwState(){}

    void onLeft();
    void onRight();

private:
    SwState();

    QStateMachine statMachine;
    QState *stateStart;
    //QState *stateCountRun;
    QState *statePause;
    QState *stateResume;
    QState *stateStop;

    SwTimer *swTimer;

signals:
    void left();
    void right();
};


#endif // SWSTATE_H
