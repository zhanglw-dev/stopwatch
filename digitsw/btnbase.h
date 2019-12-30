#ifndef BTNBASE_H
#define BTNBASE_H

#include <QWidget>
#include <QColor>


class BtnBase : public QWidget
{
    Q_OBJECT
public:
    explicit BtnBase(QWidget *parent = nullptr, QColor color = QColor(Qt::blue));
    virtual ~BtnBase() override;

    QSize sizeHint() const override;

protected:
    QColor color;

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // BTNBASE_H
