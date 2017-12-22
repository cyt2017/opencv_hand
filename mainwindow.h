#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include <QFile>
#include <QDir>
#include <opencv2/opencv.hpp>

#include "imageLabel/qimagelabel.h"
#include "file/qimagefile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void displayImage(cv::Mat rgb);
    bool operateImage(cv::Mat rgb);
    cv::Mat getThresholdImage(cv::Mat rgb);

public:
    cv::VideoCapture capture;
    cv::Mat rgbOrg;
    std::vector<cv::Mat> rgbVect;
    std::vector<QPoint> pVect;
    cv::Mat ground;
    cv::Rect rect;
    int indexImage;
    QTimer *timer;
    QPoint mousePos;

    cv::Mat groundMat;

protected slots:
    void onTimeout();
    void onReceiveMousePos(MouseType type,QPoint pp);
private slots:
    void on_captureBtn_clicked();

    void on_openFileBtn_clicked();

    void on_lastBtn_clicked();

    void on_refreshBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
