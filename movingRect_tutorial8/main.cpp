#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
//#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();

    return a.exec();
}
