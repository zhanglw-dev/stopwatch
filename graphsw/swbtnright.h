#ifndef SWBUTTONRIGHT_H
#define SWBUTTONRIGHT_H

#include "swbtn.h"


class SwButtonRight : public SwButton
{
    Q_OBJECT
public:
    SwButtonRight(SWatch *swatch, QGraphicsItem *parent=nullptr);

    void procMousePress();
    void procMouseRelease();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // SWBUTTONRIGHT_H
