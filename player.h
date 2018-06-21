#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QApplication>
#include <QTimer>
#include <QString>
#include <QObject>
#include <QPushButton>
#include <mainwindow.h>
#include<bullet.h>
#include <boss_ice.h>
#endif // PLAYER_H
class player:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public :
    player(QGraphicsItem*parent=0):QObject(),QGraphicsPixmapItem(parent){}
    virtual void hp(int hp){_hp=hp;}
    virtual int hp(){return _hp;}
    virtual void attack(double attack){_attack=attack;}
    virtual double attack(){return _attack;}
    virtual void speed(double speed){_speed=speed;}
    virtual double speed(){return _speed;}
    virtual void critical(double critical){_critical=critical;}
    virtual double critical(){return _critical;}
    virtual QString role(){return _role;}
    virtual void role(QString role){_role=role;}
    virtual QString bullet1(){return _bullet1;}
    virtual void bullet1(QString bullet1){_bullet1=bullet1;}
    virtual QString bullet2(){return _bullet2;}
    virtual void bullet2(QString bullet2){_bullet2=bullet2;}

    void initial();

    bool vinish=0,immortal=0;
    int changeflags=0,cd;
    QPushButton *count;
    QTimer *CD;
    QGraphicsPixmapItem *skill_icon;

public slots:
    void flash();
    void skill();
    void cool_down();
    void fly();




private:
    int _hp;
    QTimer *timer;
    double _attack,_speed,_critical;
    QString _role,_bullet1,_bullet2;


};
