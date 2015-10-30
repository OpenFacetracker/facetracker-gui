#include "mainwindow.h"
#include <QApplication>
#include "ui_loader.h"
#include "loader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    loader l;
    w.show();
    l.show();

    return a.exec();
}
