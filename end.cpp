#include "end.h"
extern MainWindow *w;
end::end()
{





}

void end::end_scene()
{
    score=new QGraphicsTextItem;
    score->setFont(w->font);
    score->setPos(900,200);
    score->setDefaultTextColor(QColor(255,255,255));
    w->fight=0;
    w->releaseMouse();
    w->releaseKeyboard();
    scene=new QGraphicsScene(0,0,1201,751);
    QGraphicsPixmapItem *black,*defeat,*victory;
    black=new QGraphicsPixmapItem;
    defeat=new QGraphicsPixmapItem;
    victory=new QGraphicsPixmapItem;
    black->setPixmap(QPixmap(":/res/black.png").scaled(scene->width(),scene->height()));
    defeat->setPixmap(QPixmap(":/res/defeat.png").scaled(900,751));
    victory->setPixmap(QPixmap(":/res/victory.jpg").scaled(900,751));
    scene->addItem(black);

    menu=new QPushButton;
    menu->setText("Go back to menu");
    menu->setGeometry(950,450,200,100);
    scene->addWidget(menu);
    connect(menu,SIGNAL(clicked(bool)),w,SLOT(menu()));

    QString Score;
    if(lose==1)
    {
        scene->addItem(defeat);
        Score=QString::number(w->Score);

    }
    else
    {
        scene->addItem(victory);
        Score=QString::number(w->Score+w->count*100);
    }
    score->setPlainText("Score\n"+Score);
    scene->addItem(score);







}


