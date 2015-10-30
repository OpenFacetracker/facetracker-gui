#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Header/ft.h"
#include "Header/ft_draw.h"
#include "Header/ft_recognise.h"
#include "start.h"
#include "ui_start.h"
#include "loader.h"
#include "ui_loader.h"
#include "chose_camera.h"
#include "ui_chose_camera.h"
#include <QThread>
#include <QTimer>
#include <QPoint>
#include <QSize>
#include <unistd.h>
#include <time.h>

using namespace std;
using namespace ft;
using namespace cu;

int stat = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    this->streamed = 0;
}

MainWindow::~MainWindow()
{
    if(this->streamed == 1){
        cvReleaseCapture(&this->ftcamera.ftcapture);
        cvReleaseHaarClassifierCascade(&this->ftcamera.ftcascade);
        cvReleaseMemStorage(&this->ftcamera.ftstorage);
    }
    delete ui;
}

void MainWindow::on_actionStart_triggered()
{
    /* show start options */
    int new_x = this->x(),new_y = this->y();
    chose_camera * scam = new chose_camera(this);
    QRect xy(QPoint(new_x-80,new_y-80),QSize(339,119));
    scam->setGeometry(xy);
    scam->show();
    cout << FT_ACTION << "opening start dialog .." << endl;
    /* open CAM0 for test */
    if(scam->isHidden()){
        cout << "test" << endl;
    }
    show_loading("CAM1");

}
void MainWindow::check_form(){

}

void MainWindow::show_loading(char * stream){
    Camera  *camera  = new Camera;
    FtUtils *utils 	 = new FtUtils;
    Console *console = new Console;
    CvCapture *capture;
    IplImage *img;
    int i = 0;
    ui->progressBar->setVisible(true);
    ui->camframe->setVisible(false);
    for(i; i<=100;i++){
        ui->progressBar->setValue(i);
    #ifdef _WIN32
        Sleep (20);
    #endif
    #ifdef linux
       //sleep(1);
    #endif
    }
    /* start streaming from CAM0 */
    cout << FT_ACTION << "opening camera " << endl;
    char KeyStop = 0; // if we press "Q", the program will stop
    this->ftcamera.ftcascade = NULL;
    this->ftcamera.ftstorage = NULL; // To define the memory space used during the treatment
    this->compteur = 0;
    srand(time(NULL));
#ifdef FT_TEST_PERFORMANCE
    this->testPerformance(stream);
#else
    /* set camframe to visible */
    ui->camframe->setVisible(true);
    ui->progressBar->setVisible(false);
    ui->actionStop->setEnabled(true);
    ui->actionStart->setEnabled(false);
    //QThread th = new QThread();
    //connect(&th, SIGNAL(started()), this, SLOT(ViolaJones(cascade,storage,KeyStop,"CAM0")));
    this->streamed = 1;
    ViolaJones(this->ftcamera.ftcascade,this->ftcamera.ftstorage,KeyStop,stream);
#endif
    delete console;
    delete utils;
    return ;

}
void MainWindow::startStream(){
    if(this->ftcamera.ftcapture){
        this->ftcamera.ftimg = cvQueryFrame(this->ftcamera.ftcapture);
        /* detect faces */
        this->fps = cvGetCaptureProperty(this->ftcamera.ftcapture, CV_CAP_PROP_FPS);
       // this->fps  = 0 ;
        ui->fps->setText(QString::number(fps));
        if(fps == 0){
            ui->image_l->setText("CAM");
        }
        if(this->ftcamera.ftcascade != NULL)
            this->ftcamera.detectFaces(this->ftcamera.ftimg, this->ftcamera.ftimg, this->ftcamera.ftcascade, this->ftcamera.ftstorage, &this->compteur);
        ui->camframe->setPixmap(QPixmap::fromImage(Ipl2QImage(this->ftcamera.ftimg)));
    }else{
        /* draw no signal */
        cout << "no signal" << endl;
        ui->camframe->setPixmap(QPixmap("img/nosig.png"));
    }
}
void MainWindow::ViolaJones(CvHaarClassifierCascade * cascade, CvMemStorage *storage, char KeyStop, char * stream)
{
    unsigned int ready = 0;
    Timer  * ft_timer   = new Timer(); /* init ft timer */
    Draw   * draw	 = new Draw();
    Camera * camera  = new Camera();
    CvCapture *capture;  //video stream recovered by the webcam //
    IplImage *img;
    QImage frame;
    Mat new_work;
    const char *filename 	= "Classifiers/haarcascade_frontalface_alt.xml";// we get the classifier
    const char *eyefile 	= "Classifiers/haarcascade_eye.xml";
    const char *mouthfile 	= "Classifiers/haarcascade_mcs_mouth.xml";
    const char *nozefile	= "Classifiers/haarcascade_mcs_nose.xml";
    const char *smilefile   = "Classifiers/haarcascade_smile.xml";
    int Compteur = 0, nbnoze = 0, nbeyes = 0, etat = 0, i = 0;
    double fps = 0;
    ifstream fstrm;
    char devPath[100];
    CvHaarClassifierCascade * eyecascad 	= NULL;
    CvHaarClassifierCascade * mouthcascad 	= NULL;
    CvHaarClassifierCascade * nozecascad 	= NULL;
    CvHaarClassifierCascade * smilecascad   = NULL;

    ft_timer->initTimer();

    /* Classifier loading
    cvLoadHaarClassifierCascade(filename which contains .xml file, window detection (px, px))*/
    /*
    cascade 	= (CvHaarClassifierCascade*)cvLoadHaarClassifierCascade( filename, cvSize(24, 24) );
    eyecascad 	= (CvHaarClassifierCascade*)cvLoadHaarClassifierCascade( eyefile, cvSize(24, 24) );
    mouthcascad = (CvHaarClassifierCascade*)cvLoadHaarClassifierCascade( mouthfile, cvSize(24, 24) );
    nozecascad	= (CvHaarClassifierCascade*)cvLoadHaarClassifierCascade( nozefile, cvSize(24, 24) );
    */
    this->ftcamera.ftcascade 	= (CvHaarClassifierCascade*)cvLoad( filename, 0, 0, 0  );
    eyecascad 	= (CvHaarClassifierCascade*)cvLoad( eyefile, 0, 0, 0  );
    mouthcascad = (CvHaarClassifierCascade*)cvLoad( mouthfile, 0, 0, 0 );
    nozecascad	= (CvHaarClassifierCascade*)cvLoad( nozefile, 0, 0, 0 );
    smilecascad = (CvHaarClassifierCascade*)cvLoad( smilefile,0,0,0);


    this->ftcamera.ftcapture = camera->getStream(stream);

    /* Initialisation de l’espace memoire */
    this->ftcamera.ftstorage = cvCreateMemStorage(0);

    /* start  a timer */

    this->timer = new QTimer(this);
    connect( this->timer, SIGNAL(timeout()), this, SLOT(startStream()));
    this->timer->start(01);

    //img  = cvQueryFrame(capture);
   // ui->camframe->setPixmap(QPixmap::fromImage(this->Ipl2QImage(img)));

    cout << FT_ERROR << "closing.." << endl;

    /* Free memory */
    delete ft_timer;
    delete draw;
    delete camera;
    //cvReleaseCapture(&capture);
   // cvReleaseHaarClassifierCascade(&cascade);
    //cvReleaseMemStorage(&storage);
}
void MainWindow::on_actionStop_triggered()
{
    /* stop streaming */
    this->timer->stop();
    ui->camframe->setVisible(true);
    ui->actionStart->setEnabled(true);
    ui->actionStop->setEnabled(false);
    cvReleaseCapture(&this->ftcamera.ftcapture);
    cvReleaseHaarClassifierCascade(&this->ftcamera.ftcascade);
    cvReleaseMemStorage(&this->ftcamera.ftstorage);
}
void MainWindow::changePixMap(CvCapture * capture){
    /*
    IplImage *img;
    QImage frame;
    cout << "changing" << endl;
    img = cvQueryFrame(capture);
    frame = this->Ipl2QImage(img);
    ui->camframe->setPixmap(QPixmap::fromImage(frame));
    */
}

QImage MainWindow::Ipl2QImage(IplImage *newImage)
{
    QImage qtemp;
    if (newImage && cvGetSize(newImage).width > 0)
    {
        int x;
        int y;
        char* data = newImage->imageData;

        qtemp= QImage(newImage->width, newImage->height,QImage::Format_RGB32 );
        for( y = 0; y < newImage->height; y++, data +=newImage->widthStep )
            for( x = 0; x < newImage->width; x++)
            {
                uint *p = (uint*)qtemp.scanLine (y) + x;
                *p = qRgb(data[x * newImage->nChannels+2],
                          data[x * newImage->nChannels+1],data[x * newImage->nChannels]);
            }
    }
    return qtemp;
}
