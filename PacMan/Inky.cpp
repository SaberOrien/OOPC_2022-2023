#include "Inky.h"
#include <QBrush>
#include <QTimer>

Inky::Inky(){
    distances = new double[4];

    currentTarget = new int[2];
    chaseCoords = new int[2];
    scatterCoords = new int[2];

    scatterCoords[0] = BOARD_WIDTH - 2;
    scatterCoords[1] = BOARD_HEIGHT - 2;

    currentDirection = UP;
    currentState = EATEN;

    color = QColor::fromRgb(0, 255, 255);

    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    setColor();

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}

void Inky::setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    chaseCoords[0] = getXIndex(playerXIndex, blinkyXIndex);
    chaseCoords[1] = getYIndex(playerYIndex, blinkyYIndex);
}

int Inky::getXIndex(int player_x, int blinky_x){
    int result = 2 * player_x - blinky_x;
    if(result < 0){
        return 0;
    }
    if(result > BOARD_WIDTH - 1){
        return BOARD_WIDTH - 1;
    }
    return result;
}

int Inky::getYIndex(int player_y, int blinky_y){
    int result = 2 * player_y - blinky_y;
    if(result < 0){
        return 0;
    }
    if(result > BOARD_HEIGHT - 1){
        return BOARD_HEIGHT - 1;
    }
    return result;
}