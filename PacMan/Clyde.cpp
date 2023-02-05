#include "Clyde.h"
#include <QBrush>
#include <QTimer>

Clyde::Clyde(){
    distances = new float[4];
    currentTarget = new int[2];
    chaseTarget = new int[2];
    scatterTarget = new int[2];
    scatterTarget[0] = 3;
    scatterTarget[1] = BOARD_HEIGHT - 2;

    currentDirection = UP;
    currentState = EATEN;

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    resetColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Clyde::resetColor(){
    setBrush(QBrush(QColor::fromRgb(255, 184, 82), Qt::SolidPattern));
}

void Clyde::determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    if(calculateDistance(xIndex, yIndex, playerXIndex, playerYIndex) > PLAYER_RADIUS){
        chaseTarget[0] = playerXIndex;
        chaseTarget[1] = playerYIndex;
    }
    else{
        chaseTarget = scatterTarget;
    }
}