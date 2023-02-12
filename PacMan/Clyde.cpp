#include "Clyde.h"
#include <QBrush>
#include <QTimer>

Clyde::Clyde(){
    distances = new double[4];
    currentTarget = new int[2];
    chaseCoords = new int[2];
    scatterCoords = new int[2];
    scatterCoords[0] = 3;
    scatterCoords[1] = BOARD_HEIGHT - 2;

    currentDirection = UP;
    currentState = EATEN;

    color = QColor::fromRgb(255, 184, 82);

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    setColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Clyde::setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    if(calculateDistance(xIndex, yIndex, playerXIndex, playerYIndex) > PLAYER_RADIUS){
        chaseCoords[0] = playerXIndex;
        chaseCoords[1] = playerYIndex;
    }
    else{
        chaseCoords = scatterCoords;
    }
}