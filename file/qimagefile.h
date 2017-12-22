#ifndef QIMAGEFILE_H
#define QIMAGEFILE_H

#include <QObject>
#include <QDir>
#include <opencv2/opencv.hpp>

class QImageFile : public QObject
{
    Q_OBJECT
public:
    explicit QImageFile(QObject *parent = 0);

public:
    bool readImageFromFile(QString name);

public:
    std::vector<cv::Mat> rgbVect;

signals:

public slots:
};

#endif // QIMAGEFILE_H
