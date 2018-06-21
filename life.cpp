#include "life.h"
extern MainWindow *w;
life::life()
{

}
void life::start()
{
    a=new QGraphicsPixmapItem;

    a->setPixmap(QPixmap(":/res/head1.jpg").scaled(100,100));
    a->setPos(10,590);
   // w->scene->addItem(static_cast<QGraphicsPixmapItem*>(a));
    b1=new QGraphicsPixmapItem;
    b1->setPixmap(QPixmap(":/res/soul.png").scaled(80,100));
    b1->setPos(120+110*0,590);
    b2=new QGraphicsPixmapItem;
    b2->setPixmap(QPixmap(":/res/soul.png").scaled(80,100));
    b2->setPos(120+110*1,590);
    b3=new QGraphicsPixmapItem;
    b3->setPixmap(QPixmap(":/res/soul.png").scaled(80,100));
    b3->setPos(120+110*2,590);
    b4=new QGraphicsPixmapItem;
    b4->setPixmap(QPixmap(":/res/soul.png").scaled(80,100));
    b4->setPos(120+110*3,590);
    b5=new QGraphicsPixmapItem;
    b5->setPixmap(QPixmap(":/res/soul.png").scaled(80,100));
    b5->setPos(120+110*4,590);

}
void life::hit()
{

}
void life::gameover()
{

}
