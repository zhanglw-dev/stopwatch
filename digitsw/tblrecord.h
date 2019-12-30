#ifndef TBLRECORD_H
#define TBLRECORD_H

#include <QTableWidget>


class TblRecord : public QTableWidget
{
    Q_OBJECT
public:
    explicit TblRecord(QWidget *parent = nullptr);
    virtual ~TblRecord();
};


#endif // TBLRECORD_H
