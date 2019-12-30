#ifndef BTNRED_H
#define BTNRED_H

#include "btnbase.h"


class BtnRed : public BtnBase
{
    Q_OBJECT
public:
    explicit BtnRed(QWidget *parent = nullptr);
    virtual ~BtnRed();
};

#endif // BTNRED_H
