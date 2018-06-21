#ifndef BOSS_H
#define BOSS_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QApplication>
#include <QTimer>
#include <QString>
#include <QObject>
#include <mainwindow.h>
#include <QDebug>
#include <bullet.h>
#endif // BOSS_H

class boss:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    public:
    boss(QGraphicsItem*parent=0):QObject(),QGraphicsPixmapItem(parent){}
        virtual void skill1();
        virtual void skill2();
        virtual void skill3();
        virtual void skill4();
        virtual void skill5();
        double hp1(){return _hp1;}
        double hp2(){return _hp2;}
        void hp1(double hp1){_hp1=hp1;}
        void hp2(double hp2){_hp2=hp2;}
        QString role1(){return _role1;}
        QString role2(){return _role2;}
        QString role3(){return _role3;}
        QString attack1(){return _attack1;}
        QString attack2(){return _attack2;}
        QString attack3(){return _attack3;}
        QString attack4(){return _attack4;}
        QString attack5(){return _attack5;}
        void role1(QString role1){_role1=role1;}
        void role2(QString role2){_role3=role2;}
        void role3(QString role3){_role3=role3;}
        void attack1(QString attack1){_attack1=attack1;}
        void attack2(QString attack2){_attack1=attack2;}
        void attack3(QString attack3){_attack1=attack3;}
        void attack4(QString attack4){_attack1=attack4;}
        void attack5(QString attack5){_attack1=attack5;}

        void change();
        void initial();
        void start();

        int step,direction,changeflags;
        bool vinish,changerole;
        int status;
        QTimer *timer,*action,*ftimer;
     public slots:
        void move();
        void attack();
        void flash();
        void CD();
     private:
        double _hp1,_hp2;
        QString _role1,_role2,_role3,_attack1,_attack2,_attack3,_attack4,_attack5;

};
