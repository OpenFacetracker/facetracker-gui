#include <iostream>
#include "loader.h"
#include "ui_loader.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QWidget>

using namespace std;

loader::loader(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::loader)
{
    ui->setupUi(this);
    /* start timer */
    this->progression = 0;
    this->timer = new QTimer(this);
    connect( this->timer, SIGNAL(timeout()), this, SLOT(onLoad()));
    this->timer->start(50);
}

loader::~loader()
{
    delete ui;
}

void loader::onLoad(){
    this->progression++;
    ui->progressBar->setValue(this->progression);
    if (this->progression == 100){
        this->timer->stop();
        /* show the mainWindow */
        MainWindow *w = new MainWindow(this);
        QWidget * q = new QWidget(w->window());
        //w->show();
        //this->setParent(q);
        //this->hide();
        this->close();
    }
}
