#include "player.h"
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"
#include <QDebug>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem (parent){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/Gun+Clip.mp3"));

    setPixmap(QPixmap(":/images/dedenne.jpg") );
    setScale(0.5);
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if(pos().x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x()+100<800)
        {
            setPos(x()+10,y());
        }
    }
    else if(event->key()==Qt::Key_Space){
        // create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());

        scene()->addItem(bullet);
        // play bullet sound
        if(bulletSound->state( )== QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }

        bulletSound->play();
    }
}

void Player::spown()
{
    // create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
