#include "Pinky.h"
#include <QBrush>
#include <QTimer>

Pinky::Pinky(){
    distances = new float[4];
    currentTarget = new int[2];
    chaseTarget = new int[2];
    scatterTarget = new int[2];
    scatterTarget[0] = 3;
    scatterTarget[1] = 1;

    currentDirection = UP;
    currentState = EATEN;

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    resetColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Pinky::resetColor() {
    setBrush(QBrush(QColor::fromRgb(255, 184, 255), Qt::SolidPattern));
}

void Pinky::determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    switch(playerDirection){
    case 0:
        chaseTarget[0] = playerXIndex;
        chaseTarget[1] = playerYIndex - CHASE_OFFSET;
        break;
    case 1:
        chaseTarget[0] = playerXIndex - CHASE_OFFSET;
        chaseTarget[1] = playerYIndex;
        break;
    case 2:
        chaseTarget[0] = playerXIndex;
        chaseTarget[1] = playerYIndex + CHASE_OFFSET;
        break;
    case 3:
        chaseTarget[0] = playerXIndex + CHASE_OFFSET;
        chaseTarget[1] = playerYIndex;
        break;
    default:
        chaseTarget = scatterTarget;
        break;
    }
}