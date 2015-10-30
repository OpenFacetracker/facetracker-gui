#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include "Header/ft.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ft::Camera ftcamera;
    QTimer *timer;
    double fps;
    int compteur;
    int streamed;
    explicit MainWindow(QWidget *parent = 0);
    QImage Ipl2QImage(IplImage *newImage);
    void ViolaJones(CvHaarClassifierCascade * cascade, CvMemStorage *storage, char KeyStop, char * stream);
    void show_loading(char * stream);
    ~MainWindow();

public slots:

        void check_form();

private slots:

        void startStream();

        void changePixMap(CvCapture *);

        void on_actionStart_triggered();

        void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
