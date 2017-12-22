#include "qimagelabel.h"

QImageLabel::QImageLabel(QWidget *parent) : QLabel(parent)
{

}

void QImageLabel::mousePressEvent(QMouseEvent *ev)
{
    point = ev->pos();
    emit sendMousePoint(MOUSE_PRESS,point);
}

void QImageLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint pp = ev->pos();
    emit sendMousePoint(MOUSE_RELEASE,pp);
}

void QImageLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint pp = ev->pos();
    emit sendMousePoint(MOUSE_MOVE,pp);
}
