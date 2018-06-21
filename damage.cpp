#include "damage.h"


void damage::fly()
{

    setPos(x(), y()-2);
    if(--step<=0) {
        this->scene()->removeItem(this);
        delete this;
    }


}
