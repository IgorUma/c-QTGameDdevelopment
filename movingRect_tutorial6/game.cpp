#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"
#include "game.h"
#include "score.h"
#include "health.h"
#include <QMediaPlayer>

Game::Game(QWidget * parent){
    // create the scene
    scene= new QGraphicsScene();
    int viewHeight = 600;
    int viewWidth = 800;
    scene->setSceneRect(0,0,viewWidth,viewHeight);// 800x600 instead of infinity by infinity
    // make the newly created scene the scene to visualize(sinse Game is a QGraphicsView ...
    // it can be used to visualize the scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(viewWidth,viewHeight);

    player = new Player();
    player->setRect(0,0,100,100);  // change the rect from 0x0 (defaule) to 100x100 pixels
    int playerY = viewWidth/2- player->rect().height()/2;
    player->setPos(playerY, viewHeight - player->rect().height());
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    // create health
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //spawn enimies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spown())); // design desision spawn lives in player (not the GOAT)
    timer->start(2000);

    // play bacgriund music

    QMediaPlayer * musicPlayer= new QMediaPlayer();
    musicPlayer->setMedia(QUrl("qrc:/sounds/Gun+Luger.wav"));
    musicPlayer->play();

    show();
}
