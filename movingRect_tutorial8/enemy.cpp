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

    //draw the graphics
    setPixmap(QPixmap(":/images/enimy.png"));
    setTransformOriginPoint(100,100);
    setRotation(180);
    setScale(0.5);
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);
    if(pos().y()>600)
    {
        game->health->decrease();
       this->scene()->removeItem(this);
       delete this;
    }
}
