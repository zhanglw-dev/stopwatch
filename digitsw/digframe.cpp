#include "digframe.h"
#include <QSizePolicy>



DigFrame::DigFrame()
{
    btnGreen = new BtnGreen();
    btnRed = new BtnRed();
    btnBlue = new BtnBlue();

    btnGreen->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnRed->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnBlue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layoutCmds = new QHBoxLayout();
    layoutCmds->addWidget(btnBlue);
    layoutCmds->addWidget(btnRed);
    layoutCmds->addWidget(btnGreen);

    digitLED = new DigitLED();
    tblRecord = new TblRecord();

    digitLED->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tblRecord->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layoutMain = new QVBoxLayout();
    layoutMain->addWidget(digitLED);
    layoutMain->addLayout(layoutCmds);
    layoutMain->addWidget(tblRecord);
    layoutMain->setStretch(0, 18);
    layoutMain->setStretch(1, 2);
    layoutMain->setStretch(2, 12);

    this->setLayout(layoutMain);
}


DigFrame::~DigFrame()
{
    delete btnGreen;
    delete btnRed;
    delete btnBlue;

    delete layoutCmds;
    delete layoutMain;
}
