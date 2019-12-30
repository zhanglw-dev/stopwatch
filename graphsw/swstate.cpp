#include "swstate.h"
#include <QDebug>


static SwState *swState = nullptr;


SwState::SwState()
{
    swTimer = SwTimer::getInstance();

    stateStart = new QState(&statMachine);
    //stateCountRun = new QState(&statMachine);
    statePause = new QState(&statMachine);
    stateResume = new QState(&statMachine);
    stateStop = new QState(&statMachine);

    stateStart->addTransition(this, SIGNAL(left()), statePause);
    //stateCountRun->addTransition(this, SIGNAL(left()), statePause);
    statePause->addTransition(this, SIGNAL(left()), stateStop);
    stateResume->addTransition(this, SIGNAL(left()), statePause);
    stateStop->addTransition(this, SIGNAL(left()), stateStop);

    stateStart->addTransition(this, SIGNAL(right()), statePause);
    //stateCountRun->addTransition(this, SIGNAL(right()), stateCountRun);
    statePause->addTransition(this, SIGNAL(right()), stateResume);
    stateResume->addTransition(this, SIGNAL(right()), statePause);
    stateStop->addTransition(this, SIGNAL(right()), stateStart);

    QObject::connect(stateStart, &QState::entered, swTimer, &SwTimer::start);
    //QObject::connect(stateCountRun, &QState::entered, swTimer, &SwTimer::countrun);
    QObject::connect(statePause, &QState::entered, swTimer, &SwTimer::pause);
    QObject::connect(stateResume, &QState::entered, swTimer, &SwTimer::resume);
    QObject::connect(stateStop, &QState::entered, swTimer, &SwTimer::stop);

    statMachine.setInitialState(stateStop);
    statMachine.start();
}


SwState* SwState::getInstance()
{
    if(!swState)
        swState = new SwState();
    return swState;
}


void SwState::onLeft()
{
    emit left();
}


void SwState::onRight()
{
    emit right();
}


