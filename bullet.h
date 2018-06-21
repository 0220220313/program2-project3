#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <mainwindow.h>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    int vx=0,vy=0;
    int step=50;
    bool is_critical;
public slots:
    void fly();
    void e_fly();
};

#endif // BULLET_H
