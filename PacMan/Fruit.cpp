#include "Fruit.h"
#include <QBrush>
#include <QList>
#include "Player.h"
#include <QGraphicsScene>
#include <QTimer>

Fruit::Fruit(){
    setRect(0, 0, FRUIT_SIZE, FRUIT_SIZE);
    setBrush(QBrush(QColor(255, 42, 4, 255), Qt::SolidPattern));

    QTimer* collectingTimer = new QTimer();
    connect(collectingTimer, SIGNAL(timeout()), this, SLOT(playerFruitCollision()));
    collectingTimer->start(START_TIMER);
}

int Fruit::getSize(){
    return FRUIT_SIZE;
}

int Fruit::getPoints(){
    return POINTS;
}

void Fruit::playerFruitCollision(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.length(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            emit collectedFruitSignal(POINTS);
            scene()->removeItem(this);
            delete this;
        }
    }
}