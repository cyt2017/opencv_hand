#include "qimagefile.h"

QImageFile::QImageFile(QObject *parent) : QObject(parent)
{
    rgbVect.clear();
}

bool QImageFile::readImageFromFile(QString name)
{
    QDir dir(name);
    if(!dir.exists())
    {
        return false;
    }
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QFileInfoList imgList = dir.entryInfoList();

    int count = imgList.count();
    cv::Mat src;
    for(int i=0;i<count;i++)
    {
        QString imgName = imgList[i].absoluteFilePath();
        src = cv::imread(imgName.toStdString());
        if(src.empty())
        {
            printf("src.empty...\n");
            continue;
        }
        rgbVect.push_back(src);
    }
    return true;
}
