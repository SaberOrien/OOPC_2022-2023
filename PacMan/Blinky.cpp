#include "Blinky.h"
#include "Constants.h"
#include <QBrush>

Blinky::Blinky(){

    distances = new float[4];

    currentTarget = new int[2];
    chaseTarget = new int[2];
    scatterTarget = new int[2];

    scatterTarget[0] = BOARD_WIDTH - 2;
    scatterTarget[1] = 2;

    currentDirection = UP;
    currentState = EATEN;

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    resetColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Blinky::resetColor() {
    setBrush(QBrush(Qt::red, Qt::SolidPattern));
}

void Blinky::determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    chaseTarget[0] = playerXIndex;
    chaseTarget[1] = playerYIndex;
}