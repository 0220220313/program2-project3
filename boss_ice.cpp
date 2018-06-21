#include "boss_ice.h"
#include "QGraphicsScene"
#include <sys/stat.h>
#include <QDebug>
extern MainWindow *w;
QTimer *a;
void boss::initial()
{
    step=0,direction=0,changeflags=0;
    vinish=0,changerole=0;
    status=0;


    setPos(900,150);
    setPixmap(QPixmap(":/res/boss_ice1.png").scaled(250,300));
    role2(":/res/boss_ice2.png");
    hp1(10000);
    hp2(15000);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
    action=new QTimer(this);
    connect(action,SIGNAL(timeout()),this,SLOT(attack()));
    action->start(3000);
    status=1;


}
void boss::skill1(){


         QTimer *bullettime=new QTimer;
         bullettime->start(10);
         bullet *b = new bullet;
         b->step=100;
         b->vx=-5;b->vy=0;
         b->setPixmap(QPixmap(":/res/ice_1.png").scaled(200,30));
         b->setPos(x()-b->pixmap().width()/2, y() + pixmap().height()/2-b->pixmap().height()/2);
         w->scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
         connect(bullettime,SIGNAL(timeout()),b,SLOT(e_fly()));





}
void boss::skill2(){
    for(int i=0;i<3;++i)
    {
         QTimer *bullettime=new QTimer;
         bullettime->start(10);
         bullet *b = new bullet;
         b->step=200;
         b->vx=-10;b->vy=0;
         b->setPixmap(QPixmap(":/res/ice_1.png").scaled(200,30));
         b->setPos(x()-b->pixmap().width()/2, y() + pixmap().height()/6*(5*i-2)-b->pixmap().height()/2);
         connect(bullettime,SIGNAL(timeout()),b,SLOT(e_fly()));
         w->scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

    }

}
void boss::skill3(){
    for(int i=0;i<5;++i)
    {
         QTimer *bullettime=new QTimer;
         bullettime->start(10);
         bullet *b = new bullet;
         b->step=200;
         b->vx=-10;b->vy=0;
         b->setPixmap(QPixmap(":/res/ice_1.png").scaled(200,30));
         b->setPos(x()-b->pixmap().width()/2, y() + pixmap().height()/6*(4*i-2)-b->pixmap().height()/2);
         connect(bullettime,SIGNAL(timeout()),b,SLOT(e_fly()));
         w->scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

    }
}
void boss::skill4(){
     int x= qrand()%100;
    for(int i=0;i<7;++i)
    {
         QTimer *bullettime=new QTimer;
         bullettime->start(10);
         bullet *b = new bullet;
         b->step=200;
         b->vx=0;b->vy=2;
         b->setPixmap(QPixmap(":/res/ice_2.png").scaled(50,400));
         b->setPos(250*i+x, -300);
         connect(bullettime,SIGNAL(timeout()),b,SLOT(e_fly()));
         w->scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

    }
}
void boss::skill5(){
    action->stop();
    timer->stop();
    setPos(900,150);
    a=new QTimer;
    a->start(5000);
    connect(a,SIGNAL(timeout()),this,SLOT(CD()));
    QTimer *bullettime=new QTimer;
    bullettime->start(10);
    bullet *b = new bullet;
    b->step=100;
    b->vx=-3;b->vy=0;
    b->setPixmap(QPixmap(":/res/ice_dragon.png").scaled(900,250));
    b->setPos(1100, y() + pixmap().height()/2-b->pixmap().height()/2);
    w->scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
    connect(bullettime,SIGNAL(timeout()),b,SLOT(e_fly()));

}

void boss::change()
{
    if(changerole!=0)
        return;
    changerole=1;
    action->stop();
    timer->stop();
    setPos(900,150);
    ftimer=new QTimer;
    connect(ftimer,SIGNAL(timeout()),this,SLOT(flash()));
    ftimer->start(500);



}

void boss::CD()
{
    action->start();
    timer->start();
    a->stop();
}
