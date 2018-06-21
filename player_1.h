#ifndef PLAYER_1_H
#define PLAYER_1_H
#include<player.h>

class player_1:public player
{
public:
    player_1(QGraphicsItem* parent=0):player(parent){this->initial();}
};

#endif // PLAYER_1_H
