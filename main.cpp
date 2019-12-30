#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include "mainframe.h"


#pragma execution_character_set("utf-8")


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainFrame mainFrame(app);

    mainFrame.show();

    return app.exec();
}
