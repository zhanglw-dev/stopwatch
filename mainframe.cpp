#include "mainframe.h"
#include "stopwatchscene.h"
#include "stopwatchview.h"
#include <QDebug>
#include <QScreen>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>


MainFrame::MainFrame(QApplication &app)
{
    ::QFrame();

    QRectF sceneRect;
    scene = new StopWatchScene(sceneRect);

    #if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
    QScreen *primaryScreen = app.primaryScreen();
    int scr_w = primaryScreen->geometry().width();
    int scr_h = primaryScreen->geometry().height();
    scene->setSceneRect(-scr_w/2, -scr_h*2/5, scr_w, scr_h);
    #else
    scene->setSceneRect(-250, -250, 500, 800);
    #endif

    view = new StopWatchView(scene);
    //view->setFixedSize(QSize(500, 800));
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->centerOn(0,0);
    //view->show();

    digFrame = new DigFrame();

    stack = new QStackedWidget(this);
    stack->addWidget(view);
    stack->addWidget(digFrame);
    stack->setCurrentIndex(0);
    //stack->show();

    btnGraph = new QPushButton();
    btnGraph->setText("Button1");

    btnDigit = new QPushButton();
    btnDigit->setText("Button2");

    QHBoxLayout *layout_top = new QHBoxLayout();
    layout_top->setMargin(0);
    layout_top->setSpacing(0);
    layout_top->addWidget(btnGraph);
    layout_top->addWidget(btnDigit);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(stack);
    layout->addLayout(layout_top);

    setLayout(layout);

    connect(btnGraph, SIGNAL(clicked()), this, SLOT(onGraph()));
    connect(btnDigit, SIGNAL(clicked()), this, SLOT(onDigit()));
}


MainFrame::~MainFrame()
{

}


void MainFrame::onGraph()
{
    //qDebug() << "on Graph";
    stack->setCurrentIndex(0);
}


void MainFrame::onDigit()
{
    //qDebug() << "on Digit";
    stack->setCurrentIndex(1);
}

