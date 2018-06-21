#include "boss.h"
extern MainWindow *w;
void boss::move()
{

    if(step++==0)
        direction=qrand()%9-4;
    else if(step==50)
        step=0;
    setPos(x(),y()+direction);
    if(y()>=300)
    {
        direction=-4;
        step=1;
    }
    if(y()<=50)
    {
        direction=4;
        step=1;
    }

}
void boss::attack()
{
    int x=qrand()%100;
    qDebug()<<x;
    if(status==1&&x<60)
        return skill1();
    if(status==1&&x>=60)
        return skill2();
    if(status==2&&x<33)
        return skill1();
    if(status==2&&x>=33&&x<55)
        return skill3();
    if(status==2&&x>=55&&x<77)
        return skill4();
    if(status==2&&x>=77)
        return skill5();
}
void boss::flash()
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
    if(changeflags>=6)
    {
        status=2;
        timer->start();
        action->start();
        //changeflags=0;
        ftimer->stop();

        setPixmap(QPixmap(":/res/boss_ice2.png").scaled(300,300));
        w->scene->addItem(this);

    }
}
void boss::start()
{

}
