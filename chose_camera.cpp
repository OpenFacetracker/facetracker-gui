#include <iostream>
#include "chose_camera.h"
#include "Header/ft.h"
#include "ui_chose_camera.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

using namespace std;

chose_camera::chose_camera(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::chose_camera)
{
    ui->setupUi(this);
}

chose_camera::~chose_camera()
{
    delete ui;
}


void chose_camera::on_pushButton_clicked()
{
    if(ui->cameranme->text().contains("CAM")){
        /* start */
        MainWindow w;
       // w.show_loading(ui->cameranme->text().toLocal8Bit().data());
        this->close();
    }else{
        /* show box error */
        QMessageBox messageBox;
        messageBox.critical(0,"Error","must contains CAM !");
        messageBox.setFixedSize(500,200);
    }
}

void chose_camera::on_pushButton_2_clicked()
{
    this->close();
    cout << FT_ERROR << "closing chose_camera frame" << endl;

}
