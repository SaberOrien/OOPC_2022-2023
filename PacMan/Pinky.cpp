#include "Pinky.h"
#include <QBrush>
#include <QTimer>

Pinky::Pinky(){
    distances = new double[4];
    currentTarget = new int[2];
    chaseCoords = new int[2];
    scatterCoords = new int[2];
    scatterCoords[0] = 3;
    scatterCoords[1] = 1;

    currentDirection = UP;
    currentState = EATEN;

    color = QColor::fromRgb(255, 184, 255);

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    setColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Pinky::setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    switch(playerDirection){
    case 0:
        chaseCoords[0] = playerXIndex;
        chaseCoords[1] = playerYIndex - CHASE_OFFSET;
        break;
    case 1:
        chaseCoords[0] = playerXIndex - CHASE_OFFSET;
        chaseCoords[1] = playerYIndex;
        break;
    case 2:
        chaseCoords[0] = playerXIndex;
        chaseCoords[1] = playerYIndex + CHASE_OFFSET;
        break;
    case 3:
        chaseCoords[0] = playerXIndex + CHASE_OFFSET;
        chaseCoords[1] = playerYIndex;
        break;
    default:
        chaseCoords = scatterCoords;
        break;
    }
}