#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <qobject.h>
#include <QMediaPlayer>
class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
    public:
    Player(QGraphicsItem *parent = 0);
        void keyPressEvent(QKeyEvent * event);
    public slots:
        void spown();
    private:
        QMediaPlayer * bulletSound;
};
#endif // PLAYER_H
