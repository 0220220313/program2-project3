#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<cstdio>
#include<string>
#include<QString>
#include<player_1.h>
#include<boss_ice.h>
#include "life.h"
#include <end.h>
#include<damage.h>
using namespace std;
QString danger= "QProgressBar{background-color:black;color:transparent}QProgressBar::chunk {background-color: red;}";
QString safe= "QProgressBar{background-color:red;color:transparent}QProgressBar::chunk {background-color: blue;}";

player *one;
boss *enemy;
life *blood;
end *gameover;
int status;
QTimer *t;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer)
{
    ui->setupUi(this);
    ui->pushButton->setIcon(QIcon(":/res/start.jpg"));
    ui->pushButton->setIconSize(QSize(250,100));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(start()));
    ui->progressBar->setVisible(0);
    font.setPixelSize(75);
    font.setBold(true);
    normal_hit.setPixelSize(50);
    normal_hit.setBold(1);
    critical_hit.setPixelSize(100);
    critical_hit.setBold(1);
    time=new QGraphicsTextItem;
    time->setFont(font);
    time->setDefaultTextColor(QColor(255,255,255));


    menu();






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(fight==0)
        return;
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if(one->y()<=75)
            return;
        up=1;
        down=0;
        if(left==1)
            one->setPos(one->x()-10, one->y() - 10);
        else if(right==1)
            one->setPos(one->x()+10, one->y() - 10);
        else
            one->setPos(one->x(), one->y() - 10);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if(one->y()>=550)return;
        down=1;
        up=0;
        if(left==1)
            one->setPos(one->x()-10, one->y() + 10);
        else if(right==1)
            one->setPos(one->x()+10, one->y() + 10);
        else
            one->setPos(one->x(), one->y() + 10);
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if(one->x()<=0)
            return;
        left=1;
        right=0;
        if(up==1)
            one->setPos(one->x() - 10, one->y() - 10);
        else if(down==1)
            one->setPos(one->x() - 10, one->y() + 10);
        else
            one->setPos(one->x() - 10, one->y());
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if(one->x()>=800)return;
        right=1;
        left=0;
        if(up==1)
            one->setPos(one->x() + 10, one->y() - 10);
        else if(down==1)
            one->setPos(one->x() + 10, one->y() + 10);
        else
            one->setPos(one->x() + 10, one->y());
        break;

    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        up=0;
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        down=0;
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        left=0;
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        right=0;
        break;
    }
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(fight==0)
        return ;
    grabMouse();
    connect(timer,SIGNAL(timeout()),this,SLOT(fire()));

 }
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
   releaseMouse();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(fire()));

}
void MainWindow::fire()
{

    QTimer *bullettime;
    bullettime=new QTimer;
    bullettime->start(10);
    bullet *b = new bullet;
    if(qrand() % 10 == 0) {
        b->setPixmap(QPixmap(":/res/bullet2.png").scaled(100, 180));
        b->is_critical=1;
    }
    else {
        b->setPixmap(QPixmap(":/res/bullet1.png").scaled(100, 125));
        b->is_critical=0;

      }
   // b->setPos(200,200);
    b->setPos(one->x()+one->pixmap().width(), one->y() + one->pixmap().height() / 2  - b->pixmap().height()/2);
    b->connect(bullettime,SIGNAL(timeout()),b,SLOT(fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));



}


void MainWindow:: start()
{
    fight=1;
    Score=0;
    count=360;
    second=new QTimer;

    connect(second,SIGNAL(timeout()),this,SLOT(countdown()));
    second->start(1000);

    ui->pushButton->setVisible(0);
    QGraphicsPixmapItem *background =new QGraphicsPixmapItem;
    QGraphicsPixmapItem *black =new QGraphicsPixmapItem;
    background->setPixmap(QPixmap(":/res/background.jpg").scaled(1200,580));
    black->setPixmap(QPixmap(":/res/black.png").scaled(1201,751));
    black->setPos(0,0);
    background->setPos(0,0);
    scene->addItem(black);
    scene->addItem(background);
    one=new player_1();
    scene->addItem(one);
    enemy=new boss_ice();
    scene->addItem(enemy);


    timer->start(500);
    right=left=up=down=0;
    QProgressBar *bar=ui->progressBar;
    bar->setVisible(1);
    bar->setStyleSheet(safe);
    bar->setRange(0,enemy->hp1());
    bar->setValue(enemy->hp1());

    blood=new life;
    blood->start();
    scene->addItem(blood->a);
    scene->addItem(blood->b1);
    scene->addItem(blood->b2);
    scene->addItem(blood->b3);
    scene->addItem(blood->b4);
    scene->addItem(blood->b5);




}
void MainWindow::hit(bool is_critical)
{
    Score+=one->attack();
    QTimer *damagetime=new QTimer;
    damage *d=new damage;
    d->step=100;
    int x=qrand()%50-24;
    if(enemy->status==1)
    {
        if(is_critical==1)
        {
             enemy->hp1(enemy->hp1()-2*one->attack());
             d->setPlainText(QString::number(2*one->attack()));
             d->setFont(critical_hit);
             d->setDefaultTextColor(QColor(255,0,0));
             d->setPos(enemy->x()+100+x,enemy->y()+20);
             scene->addItem(d);

        }
       else
        {
             enemy->hp1(enemy->hp1()-one->attack());
             d->setPlainText(QString::number(one->attack()));
             d->setFont(normal_hit);
             d->setDefaultTextColor(QColor(0,0,255));
             d->setPos(enemy->x()+120+x,enemy->y()+20);
             scene->addItem(d);
        }
        ui->progressBar->setValue((enemy->hp1()));
        if(enemy->hp1()<=0)
        {
            ui->progressBar->setStyleSheet(danger);
            ui->progressBar->setRange(0,enemy->hp2());
            ui->progressBar->setValue(enemy->hp2());
            enemy->change();
            //enemy->status=2;
        }


    }
    if(enemy->status==2)
    {
        if(is_critical==1)
        {
             enemy->hp2(enemy->hp2()-2*one->attack());
             d->setPlainText(QString::number(2*one->attack()));
             d->setFont(critical_hit);
             d->setDefaultTextColor(QColor(255,0,0));
             d->setPos(enemy->x()+100+x,enemy->y()+20);
             scene->addItem(d);

        }
       else
        {
             enemy->hp2(enemy->hp2()-one->attack());
             d->setPlainText(QString::number(one->attack()));
             d->setFont(normal_hit);
             d->setDefaultTextColor(QColor(0,0,255));
             d->setPos(enemy->x()+120+x,enemy->y()+20);
             scene->addItem(d);
        }
        ui->progressBar->setValue(enemy->hp2());
        if(enemy->hp2()<=0)
        {
            gameover=new end;
            gameover->lose=0;
            gameover->end_scene();
            delete one;
            delete enemy;
            second->stop();
            ui->progressBar->setVisible(0);
            ui->graphicsView->setScene(gameover->scene);
            scene->removeItem(time);
        }
    }
    connect(damagetime,SIGNAL(timeout()),d,SLOT(fly()));
    damagetime->start(20);

}

void MainWindow::get_hurt()
{
    if(one->immortal==1)
        return;
    one->hp(one->hp()-1);
    one->immortal=1;
    ftimer=new QTimer;
    ftimer->start(300);
    connect(ftimer,SIGNAL(timeout()),one,SLOT(flash()));
    if(one->hp()==4)
    {
        scene->removeItem(blood->b5);
        delete blood->b5;
    }
    if(one->hp()==3)
    {
        scene->removeItem(blood->b4);
        delete blood->b4;
    }
    if(one->hp()==2)
    {
        scene->removeItem(blood->b3);
        delete blood->b3;
    }
    if(one->hp()==1)
    {
        scene->removeItem(blood->b2);
        delete blood->b2;
    }
    if(one->hp()<=0)
    {
        scene->removeItem(blood->b1);
        delete blood->b1;
        gameover=new end;
        gameover->lose=1;
        gameover->end_scene();
        delete one;
        delete enemy;
        second->stop();
        ui->progressBar->setVisible(0);
        ui->graphicsView->setScene(gameover->scene);
        scene->removeItem(time);
    }

}

void MainWindow::menu()
{
    scene=new QGraphicsScene(0, 0, 1201, 751);
    ui->graphicsView->setScene(scene);
    ui->pushButton->setVisible(1);
    QGraphicsPixmapItem *start_background =new QGraphicsPixmapItem;
    start_background->setPixmap(QPixmap(":/res/start_background.jpg").scaled(1200,750));
    start_background->setPos(0,0);
    scene->addItem(start_background);


}

void MainWindow::countdown()
{

    QString m,s,total;
    m=QString::number(count/60);
    s=QString::number(count%60);
    if(s=="0")
        s="00";
    total=m+":"+s;
    time->setPlainText(total);
    time->setPos(1000,600);
    time->setVisible(1);
    scene->addItem(time);
     count--;


}

void MainWindow::skill()
{
    t=new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(skill_hit()));
    t->start(100);
    status=20;
    skill_icon=new QGraphicsPixmapItem;
    skill_icon->setPixmap(QPixmap(":/res/skill1.png").scaled(250,250));
    skill_icon->setPos(enemy->x()-20,enemy->y()+10);
    skill_icon->setTransformOriginPoint(125,125);

    scene->addItem(skill_icon);

}
void MainWindow::skill_hit()
{
    if(--status<=0)
    {
        scene->removeItem(skill_icon);
        t->stop();
        return;
    }
    skill_icon->setRotation(qrand()%90);
    hit(0);
}

























