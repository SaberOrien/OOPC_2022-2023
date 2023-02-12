#include "Coin.h"
#include <QBrush>
#include <QList>
#include <QGraphicsScene>
#include "Player.h"
#include <QTimer>

Coin::Coin(){
    setRect(0, 0, COIN_SIZE, COIN_SIZE);
    setBrush(QBrush(QColor(196, 202, 206, 255) , Qt::SolidPattern));

    QTimer* collectingTimer = new QTimer();
    connect(collectingTimer, SIGNAL(timeout()), this, SLOT(playerCoinCollision()));
    collectingTimer->start(START_TIMER);
}

int Coin::getSize(){
    return COIN_SIZE;
}

int Coin::getPoints(){
    return POINTS;
}

void Coin::playerCoinCollision(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.length(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            emit collectedCoinSignal(POINTS);
            scene()->removeItem(this);
            delete this;
        }
    }
}