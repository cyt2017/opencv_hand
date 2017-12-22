#ifndef QIMAGELABEL_H
#define QIMAGELABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

enum MouseType
{
    MOUSE_NULL,
    MOUSE_MOVE,
    MOUSE_RELEASE,
    MOUSE_PRESS,
};

class QImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QImageLabel(QWidget *parent = 0);


    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);
    QPoint point;
signals:
    void sendMousePoint(MouseType type,QPoint p);

public slots:
};

#endif // QIMAGELABEL_H
