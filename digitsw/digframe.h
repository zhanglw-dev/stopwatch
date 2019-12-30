#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "digitled.h"
#include "btnblue.h"
#include "btngreen.h"
#include "btnred.h"
#include "tblrecord.h"


class DigFrame : public QFrame
{
    Q_OBJECT
public:
    DigFrame();
    virtual ~DigFrame();

private:
    QHBoxLayout *layoutCmds;
    QVBoxLayout *layoutMain;

    BtnGreen *btnGreen;
    BtnRed *btnRed;
    BtnBlue *btnBlue;

    DigitLED *digitLED;
    TblRecord *tblRecord;
};
