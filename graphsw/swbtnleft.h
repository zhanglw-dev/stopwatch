#ifndef SWBUTTONLEFT_H
#define SWBUTTONLEFT_H

#include "swbtn.h"


class SwButtonLeft : public SwButton
{
    Q_OBJECT
public:
    SwButtonLeft(SWatch *swatch, QGraphicsItem *parent=nullptr);

    void procMousePress();
    void procMouseRelease();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // SWBUTTONLEFT_H
