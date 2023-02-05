#include "Inky.h"
#include <QBrush>
#include <QTimer>

Inky::Inky(){
    distances = new float[4];

    currentTarget = new int[2];
    chaseTarget = new int[2];
    scatterTarget = new int[2];

    scatterTarget[0] = BOARD_WIDTH - 2;
    scatterTarget[1] = BOARD_HEIGHT - 2;

    currentDirection = UP;
    currentState = EATEN;

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    resetColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Inky::resetColor() {
    setBrush(QBrush(QColor::fromRgb(0, 255, 255), Qt::SolidPattern));
}

void Inky::determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    chaseTarget[0] = getIndex(playerXIndex, blinkyXIndex, 0);
    chaseTarget[1] = getIndex(playerYIndex, blinkyYIndex, 1);
}

int Inky::getIndex(int a, int b, int mode){
    int result = (2 * a - b);

    if(result < 0){
        return 0;
    }

    if(mode == 0){
        if(result > BOARD_WIDTH - 1){
            return BOARD_WIDTH - 1;
        }
    }
    else if(mode == 1){
        if(result > BOARD_HEIGHT - 1){
            return BOARD_HEIGHT - 1;
        }
    }

    return result;
}