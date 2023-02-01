#include "Ghost.h"
#include <QList>
#include "Player.h"

void Ghost::setXIndex(int givenIndex){
    xIndex = givenIndex;
}

void Ghost::setYIndex(int givenIndex){
    yIndex = givenIndex;
}

void Ghost::playerGhostCollision(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            emit gameOverSignal();
        }
    }
}