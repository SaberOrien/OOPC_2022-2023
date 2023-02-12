#include "Blinky.h"
#include "Constants.h"
#include <QBrush>

Blinky::Blinky(){

    distances = new double[4];

    currentTarget = new int[2];
    chaseCoords = new int[2];
    scatterCoords = new int[2];

    scatterCoords[0] = BOARD_WIDTH - 2;
    scatterCoords[1] = 2;

    currentDirection = UP;
    currentState = EATEN;

    color = Qt::red;

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    setColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Blinky::setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    chaseCoords[0] = playerXIndex;
    chaseCoords[1] = playerYIndex;
}