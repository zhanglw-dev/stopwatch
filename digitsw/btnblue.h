#ifndef BTNBLUE_H
#define BTNBLUE_H

#include "btnbase.h"


class BtnBlue : public BtnBase
{
    Q_OBJECT
public:
    explicit BtnBlue(QWidget *parent = nullptr);
    virtual ~BtnBlue();
};

#endif // BTNBLUE_H
