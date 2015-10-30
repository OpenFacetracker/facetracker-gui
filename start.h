#ifndef START_H
#define START_H

#include <QDialog>
#include "ui_start.h"

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private:
    Ui::start *ui;
};

#endif // START_H
