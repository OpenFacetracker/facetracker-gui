#ifndef LOADER_H
#define LOADER_H

#include <QFrame>

namespace Ui {
class loader;
}

class loader : public QFrame
{
    Q_OBJECT

public:
    explicit loader(QWidget *parent = 0);
    ~loader();

private slots:
    void onLoad();

private:
    int progression;
    QTimer * timer;
    Ui::loader *ui;
};

#endif // LOADER_H
