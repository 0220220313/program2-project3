#ifndef END_H
#define END_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QApplication>
#include <QTimer>
#include <QObject>
#include <QPushButton>
#include "bullet.h"
#include <life.h>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QFont>


class end:public QObject
{
     Q_OBJECT
public:
    end();
    QGraphicsTextItem *score;
    QPushButton *menu;
    void end_scene();
    bool lose;
    QGraphicsScene *scene;








};

#endif // END_H
