#ifndef DIGITLED_H
#define DIGITLED_H

#include <QWidget>


class DigitLED : public QWidget
{
    Q_OBJECT
public:
    explicit DigitLED(QWidget *parent = nullptr);
    virtual ~DigitLED() override;

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // DIGITLED_H
