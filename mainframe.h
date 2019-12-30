#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QApplication>
#include <QFrame>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include "stopwatchscene.h"
#include "stopwatchview.h"
#include "digframe.h"


class MainFrame : public QFrame
{
    Q_OBJECT
public:
    MainFrame(QApplication &app);
    virtual ~MainFrame();

private:
    StopWatchScene *scene;
    StopWatchView *view;
    DigFrame *digFrame;
    QStackedWidget *stack;
    QPushButton *btnGraph;
    QPushButton *btnDigit;

private slots:
    void onGraph();
    void onDigit();
};


#endif // MAINFRAME_H
