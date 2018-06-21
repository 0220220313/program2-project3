#ifndef LIFE_H
#define LIFE_H
#include <mainwindow.h>

class life
{
public:
    life();
    void start();
    void hit();
    void gameover();
    QGraphicsPixmapItem *a,*b1,*b2,*b3,*b4,*b5;

};

#endif // LIFE_H
