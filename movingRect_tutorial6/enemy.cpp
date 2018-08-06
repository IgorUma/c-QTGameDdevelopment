#include "enemy.h"
#include "game.h"
#include<QTimer>
#include <QDebug>
#include<QGraphicsScene>
#include <stdlib.h>  // rand() really largre int
#include <QTcore/qmath.h>

extern Game * game;
Enemy::Enemy()
{
    // set random position
    int random_number = rand() % 700;//(qCeil(scene()->width())-100)
    setPos(random_number,0);
    // drew the rect
    setRect(0,0,100,50);
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);
    if(pos().y()+ rect().height()> scene()->height())
    {
        game->health->decrease();
       this->scene()->removeItem(this);
       delete this;
    }
}
