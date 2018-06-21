#ifndef DAMAGE_H
#define DAMAGE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsTextItem>
#include <mainwindow.h>

class damage :  public QGraphicsTextItem
{
    Q_OBJECT
public:
    int step;

public slots:
    void fly();

};

#endif // DAMAGE_H
