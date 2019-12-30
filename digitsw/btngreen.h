#ifndef BTNGREEN_H
#define BTNGREEN_H

#include "btnbase.h"


class BtnGreen : public BtnBase
{
    Q_OBJECT
public:
    explicit BtnGreen(QWidget *parent = nullptr);
    virtual ~BtnGreen();
};

#endif // BTNGREEN_H
