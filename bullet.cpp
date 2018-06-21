#include "bullet.h"
#include<boss_ice.h>
#include <typeinfo>
#include <QDebug>
#include <player_1.h>
extern MainWindow *w;


bullet::bullet()
{

}

void bullet::fly()
{
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))==typeid(boss_ice))
        {
            if(--step!=0)
                continue;
            w->hit(is_critical);
            //this->scene()->removeItem(colliding_items[i]);
            this->scene()->removeItem(this);
            delete this;
            return;
        }

    }
    setPos(x()+3, y());
    if(x() > 1200) {

        this->scene()->removeItem(this);
        delete this;
    }


}
void bullet::e_fly()
{
    if(--step!=0)
    {
        return;
    }
    setPos(x()+vx,y()+vy);

    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))==typeid(player_1))
            w->get_hurt();
    }



    if(x()<-1200)
    {
        this->scene()->removeItem(this);
        delete this;
    }
    step=1;
}
