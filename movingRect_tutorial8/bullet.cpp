#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include<QTimer>
#include <QDebug>
#include<QGraphicsScene>

extern Game * game; // there is an external global object called game

Bullet::Bullet()
{
    // drew the rect
    // old setRect(0,0,10,50);

    // draw graphics
    setPixmap(QPixmap(":/images/Bullet_Pose.png"));
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // if bullet collieds with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid(*colliding_items[i])==typeid(Enemy)){
            // increase score
            game->score->increase();
            // remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // remove from the heap
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    // move bullet up
    setPos(x(),y()-5);
    if(pos().y()+ 50< 0)
    {
       this->scene()->removeItem(this);
       delete this;
       //qDebug()<<"bullet deleted";
    }
}
