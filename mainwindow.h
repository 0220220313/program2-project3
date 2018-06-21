#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QApplication>
#include <QTimer>
#include <QObject>
#include "bullet.h"
#include <life.h>
#include <QKeyEvent>
#include <end.h>
#include <QGraphicsTextItem>
#include <QFont>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool up,down,left,right,fight=0;
    QGraphicsScene *scene;
    int step=0,count,Score;
    void hit(bool is_critical);
    void get_hurt();
    void skill();
    QTimer *ftimer,*second;
    Ui::MainWindow *ui;
    QGraphicsPixmapItem *skill_icon;
    QGraphicsTextItem *time;
    QFont font,normal_hit,critical_hit;
public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void fire();
    void start();
    void menu();
    void countdown();
    void skill_hit();

private:

    QGraphicsPixmapItem *boss;
    QTimer *timer;
};

#endif // MAINWINDOW_H














