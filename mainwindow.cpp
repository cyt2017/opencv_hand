#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ground = cv::Mat::zeros(480,640,CV_8UC3);
    groundMat = ~(cv::Mat::zeros(480,640,CV_8UC3));
    rect.x = -1;
    rect.y = -1;
    rect.width = -1;
    rect.height = -1;
    indexImage = -1;
    capture.open(1);
    if(!capture.isOpened())
    {
        printf("capture is opened error!");
        return ;
    }

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timer->start(20);

    ui->label->setMouseTracking(true);
    connect(ui->label,SIGNAL(sendMousePoint(MouseType,QPoint)),this,SLOT(onReceiveMousePos(MouseType,QPoint)));
    connect(ui->label,SIGNAL(sendMouseMovePoint(MouseType,QPoint)),this,SLOT(onReceiveMousePos(MouseType,QPoint)));
}

MainWindow::~MainWindow()
{
    timer->deleteLater();
    delete ui;
}

void MainWindow::onTimeout()
{
    while(!capture.read(rgbOrg));


    if(ui->radioButton_org->isChecked())
    {
        cv::Mat src = rgbOrg.clone();
        QPoint pos = mousePos;
        cv::line(src,cv::Point(0,pos.y()),cv::Point(src.cols,pos.y()),cv::Scalar(0,0,255));
        cv::line(src,cv::Point(pos.x(),0),cv::Point(pos.x(),src.rows),cv::Scalar(0,0,255));
        displayImage(src);
    }
    else if(ui->radioButton_diff->isChecked())
    {
        QPoint pos = mousePos;
        cv::Mat dst = getThresholdImage(rgbOrg);
        //cv::Rect rect(0,0,200,200);
        cv::line(dst,cv::Point(0,pos.y()),cv::Point(dst.cols,pos.y()),cv::Scalar(255));
        cv::line(dst,cv::Point(pos.x(),0),cv::Point(pos.x(),dst.rows),cv::Scalar(255));
        displayImage(dst);
    }
    else if(ui->radioButton_readFile->isChecked())
    {
        connect(ui->openFileBtn,SIGNAL(clicked(bool)),this,SLOT(on_openFileBtn_clicked()));
    }
}

void MainWindow::onReceiveMousePos(MouseType type, QPoint pp)
{
    mousePos = pp;
    QString ss;
    ss.sprintf("[%d,%d]",pp.x(),pp.y());
    ui->label_mousePos->setText(ss);

//    if(indexImage <0)
//    {
//        return ;
//    }
    cv::Mat rgb;
    if(ui->radioButton_org->isChecked())
    {
        rgb = rgbOrg.clone();
    }
    if(ui->radioButton_diff->isChecked())
    {
        rgb = getThresholdImage(rgbOrg.clone());
    }
    cv::Mat src = rgb.clone();

//    if(type == MOUSE_RELEASE)
//    {
//        pVect.push_back(pp);
//    }
//    int count = pVect.size();
//    if(count > 0)
//    {
//        for(int i=0;i<count;i++)
//        {
//            QPoint p = pVect[i];
//            cv::Point pCV(p.x(),p.y());
//            QString ss;
//            ss.sprintf("%d",i);
//            cv::circle(src,pCV,2,cv::Scalar(255,0,0),2);
//            cv::putText(src,ss.toStdString(),pCV,0.5,1,cv::Scalar(0,0,255));
//        }
//    }
    if(type == MOUSE_PRESS)
    {
        if(rect.x == -1 && rect.y == -1)
        {
            rect.x = pp.x();
            rect.y = pp.y();
        }
    }
    if(type == MOUSE_RELEASE)
    {
        if(rect.width == -1 &&rect.height== -1&& rect.x != -1 && rect.y != -1)
        {
            rect.height = pp.y()-rect.y;
            rect.width = pp.x()-rect.x;

            cv::Mat rectSrc = rgbOrg(rect).clone();
            cv::Mat dst = getThresholdImage(rgbOrg.clone());
            cv::Mat rectDst = dst(rect).clone();

            for(int row=0;row<rectDst.rows;row++)
            {
                for(int col=0;col<rectDst.cols;col++)
                {
                    if(rectDst.at<uchar>(row,col) == 0)
                    {
                        rectSrc.at<cv::Vec3b>(row,col)[0] = 0;
                        rectSrc.at<cv::Vec3b>(row,col)[1] = 0;
                        rectSrc.at<cv::Vec3b>(row,col)[2] = 0;
                    }
                }
            }
            QString ss;
            for(int i=0;i<9999;i++)
            {
                ss.sprintf("../handImage/%d.jpg",i);
                QFile file(ss);
                if(!file.exists())
                {
                  cv::imwrite(ss.toStdString(),rectSrc);
                  rect.x = -1;
                  rect.y = -1;
                  rect.width = -1;
                  rect.height = -1;
                  break;
                }

            }
        }
    }
    displayImage(src);
}


void MainWindow::displayImage(cv::Mat rgb)
{
    cv::Mat src = rgb.clone();
    QImage img;
    if(src.channels() == 3)
    {
        cv::cvtColor(src,src,CV_RGB2BGR);
        img = QImage(src.data,src.cols,src.rows,src.cols*3,QImage::Format_RGB888);
    }
    else if(src.channels() == 1)
    {
        img = QImage(src.data,src.cols,src.rows,src.cols ,QImage::Format_Indexed8);
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

bool MainWindow::operateImage(cv::Mat rgb)
{
    cv::Mat src = rgb.clone();
    cv::Rect ccomp;
    cv::floodFill(src, cv::Point(10,10), cv::Scalar(0,0,0), &ccomp, cv::Scalar(7,7,7),cv::Scalar(7,7,7));
    cv::imshow("dst",src);
}

cv::Mat MainWindow::getThresholdImage(cv::Mat rgb)
{
    cv::Mat src = rgb.clone();
    cv::Mat dst,gray;

    cv::absdiff(src,ground,dst);
    cv::cvtColor(dst,gray,CV_RGB2GRAY);
    cv::threshold(gray,dst,20,255,CV_THRESH_BINARY);
    return dst;
}

void MainWindow::on_captureBtn_clicked()
{
    cv::Mat src = rgbOrg.clone();
    QString ss;
    for(int i=0;i<9999;i++)
    {
        ss.sprintf("../handImage/%d.jpg",i);
        QFile file(ss);
        if(!file.exists())
        {
          cv::imwrite(ss.toStdString(),src);
          break;
        }
    }
}

void MainWindow::on_openFileBtn_clicked()
{
    QImageFile imgFile;

    if(indexImage == -1)
    {
        QString name = "../handImage/";
        indexImage = 0;
        if(!imgFile.readImageFromFile(name))
        {
            return ;
        }
    }
    cv::Mat mat = imgFile.rgbVect[indexImage];
    cv::Mat mask = mat.clone();

    cv::Rect maskRect;
    maskRect.x      = (groundMat.cols-mask.cols)/2;
    maskRect.y      = (groundMat.rows-mask.rows)/2;
    maskRect.width  = mask.cols;
    maskRect.height = mask.rows;

    mask.copyTo(groundMat(maskRect));
    cv::imshow("copy",groundMat);
    //cv::waitKey(500);
}

void MainWindow::on_lastBtn_clicked()
{
    indexImage++;
    if(indexImage < 0)
    {
        return ;
    }
    cv::Mat src = rgbVect[indexImage].clone();
    displayImage(src);
}

void MainWindow::on_refreshBtn_clicked()
{
    ground = rgbOrg.clone();
}
