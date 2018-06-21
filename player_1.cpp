#include "player_1.h"
#include<typeinfo>
extern MainWindow *w;
QTimer *flytime;
void player::initial()
{
    setPos(0,350);
    setPixmap(QPixmap(":/res/role1.png").scaled(75,100));
    hp(5);
    attack(150);
    speed(1);
    critical(10);
    //role(":/res/role1.png");
    bullet1(":/res/bullet1.png");
    bullet2(":/res/bullet2.png");

    count=new QPushButton;
    count->setIcon(QIcon(":/res/icon.png"));
    count->setIconSize(QSize(110,110));
    CD=new QTimer;
    connect(count,SIGNAL(clicked(bool)),this,SLOT(skill()));
    connect(CD,SIGNAL(timeout()),this,SLOT(cool_down()));
    count->setGeometry(780,590,120,120);
    w->scene->addWidget(count);

}
void player::flash()
{
    if(vinish==0)
    {
        this->scene()->removeItem(this);
        vinish=1;
        changeflags++;
    }
    else
    {
        w->scene->addItem(this);
        vinish=0;
        changeflags++;
    }
    if(changeflags>10)
    {
        w->scene->addItem(this);
        w->ftimer->stop();
        immortal=0;
        changeflags=0;
    }
}


void player::skill()
{
    cd=30;
    CD->start(1000);
    disconnect(count,SIGNAL(clicked(bool)),this,SLOT(skill()));
    skill_icon=new QGraphicsPixmapItem;
    skill_icon->setPixmap(QPixmap(":/res/a.png").scaled(250,500));
    skill_icon->setPos(x()+150,100);
    w->scene->addItem(skill_icon);

    flytime=new QTimer;
    connect(flytime,SIGNAL(timeout()),this,SLOT(fly()));
    flytime->start(20);

}

void player::cool_down()
{
    if(--cd<=0)
    {
        connect(count,SIGNAL(clicked(bool)),this,SLOT(skill()));
        count->setText(" ");
        CD->stop();
    }
    else
        count->setText(QString::number(cd));
}
void player::fly()
{
    if(skill_icon->x()> 800) {
        flytime->stop();
        w->scene->removeItem(skill_icon);
        w->skill();
        return;
    }
    skill_icon->setPos(skill_icon->x()+10,skill_icon->y());
    if(skill_icon->x()> 1000) {

        w->scene->removeItem(skill_icon);

        return;
    }


}
