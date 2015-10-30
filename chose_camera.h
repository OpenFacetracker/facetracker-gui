#ifndef CHOSE_CAMERA_H
#define CHOSE_CAMERA_H

#include <QFrame>
#include <QAbstractButton>

namespace Ui {
class chose_camera;
}

class chose_camera : public QFrame
{
    Q_OBJECT

public:
    explicit chose_camera(QWidget *parent = 0);
    ~chose_camera();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::chose_camera *ui;
};

#endif // CHOSE_CAMERA_H
