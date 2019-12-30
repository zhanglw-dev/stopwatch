#ifndef CMDBUTTON_H
#define CMDBUTTON_H


#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QRectF>
#include "swatch.h"

#define CMD_BUTTON_LOC_LEFT  0
#define CMD_BUTTON_LOC_RIGHT 1


class CmdButton : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    CmdButton(int loc, QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void onPress();
    void onRelease();

private:
    int loc;
    QRectF bindRectF;
    bool is_pressing;
    QWidget *_widget;
};


#endif // CMDBUTTON_H
