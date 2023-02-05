#include "Ghost.h"
#include <QList>
#include <QtMath>
#include <QBrush>
#include "Player.h"
#include "GhostPaths.h"

void Ghost::setXIndex(int givenIndex){
    xIndex = givenIndex;
}

void Ghost::setYIndex(int givenIndex){
    yIndex = givenIndex;
}

int Ghost::getXIndex() const{
    return xIndex;
}

int Ghost::getYIndex() const{
    return yIndex;
}

void Ghost::playerGhostCollision(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            if(currentState == CHASE || currentState == SCATTER){
                emit gameOverSignal();
            }
            else if(currentState == FRIGHTENED){
                currentState = EATEN;
                setBrush(QBrush(Qt::gray, Qt::SolidPattern));
                emit ghostEatenSignal(POINTS);
            }
        }
    }
}

void Ghost::determineBehaviour(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex){
    
    switch (currentState)
    {
    case CHASE:
        determineChaseTarget(playerXIndex, playerYIndex, playerDirection, blinkyXIndex, blinkyYIndex);
        currentTarget = chaseTarget;
        break;
    case SCATTER:
        currentTarget = scatterTarget;
        scatterBehaviour();
        break;
    case EATEN:
        eatenBehaviour();
        break;
    case FRIGHTENED:
        currentTarget = scatterTarget;
        break;
    default:
        break;
    }
    
    
    if((((int)y() - OFFSET) % BLOCK_SIZE == 0) && (((int)x() - OFFSET) % BLOCK_SIZE == 0)){
        choosePath();
    }
    move();
}

void Ghost::eatenBehaviour(){
    if(xIndex == homeTarget[0] && yIndex == homeTarget[1]){
        //paths[(yIndex + 1)*BOARD_WIDTH + xIndex] = 1;
        //paths[(yIndex + 1)*BOARD_WIDTH + (xIndex + 1)] = 1;
        currentDirection = UP;
        currentState = SCATTER;
        resetColor();
    }
    else{
        currentTarget = homeTarget;
    }
}

void Ghost::scatterBehaviour(){
    if(xIndex == scatterTarget[0] && yIndex == scatterTarget[1]){
        currentState = CHASE;
    }
}

void Ghost::setCurrentState(int const& newState) {
    switch(newState){
    case 0:
        currentState = CHASE;
        resetColor();
        break;
    case 1:
        currentState = SCATTER;
        resetColor();
        break;
    case 2:
        currentState = EATEN;
        break;
    case 3:
        currentState = FRIGHTENED;
        setBrush(QBrush(Qt::green, Qt::SolidPattern));
        break;
    default:
        break;
    }
}

int Ghost::getCurrentState() const{
    return currentState;
}

void Ghost::choosePath() {
    float minDistance = 1000;
    int index = 0;

    arrayReset();

    if(currentDirection == UP){
        if(paths[(yIndex - 1) * BOARD_WIDTH + xIndex] == 0){
            distances[UP] = calculateDistance(xIndex, yIndex-1, currentTarget[0], currentTarget[1]);
        }
        if(paths[yIndex * BOARD_WIDTH + (xIndex-1)] == 0){
            distances[LEFT] = calculateDistance(xIndex-1, yIndex, currentTarget[0], currentTarget[1]);
        }
        if(paths[yIndex * BOARD_WIDTH + (xIndex+1)] == 0){
            distances[RIGHT] = calculateDistance(xIndex+1, yIndex, currentTarget[0], currentTarget[1]);
        }
    }
    else if(currentDirection == LEFT){
        if(xIndex > 0){
            if(paths[(yIndex - 1) * BOARD_WIDTH + xIndex] == 0){
                distances[UP] = calculateDistance(xIndex, yIndex-1, currentTarget[0], currentTarget[1]);
            }
            if(paths[yIndex * BOARD_WIDTH + (xIndex-1)] == 0){
                distances[LEFT] = calculateDistance(xIndex-1, yIndex, currentTarget[0], currentTarget[1]);
            }
            if(paths[(yIndex + 1) * BOARD_WIDTH + xIndex] == 0){
                distances[DOWN] = calculateDistance(xIndex, yIndex+1, currentTarget[0], currentTarget[1]);
            }
        }
        else{
            distances[LEFT] = 0;
        }
    }
    else if(currentDirection == DOWN){
        if(paths[yIndex * BOARD_WIDTH + (xIndex-1)] == 0){
            distances[LEFT] = calculateDistance(xIndex-1, yIndex, currentTarget[0], currentTarget[1]);
        }
        if(paths[(yIndex + 1) * BOARD_WIDTH + xIndex] == 0){
                distances[DOWN] = calculateDistance(xIndex, yIndex+1, currentTarget[0], currentTarget[1]);
            }
        if(paths[yIndex * BOARD_WIDTH + (xIndex+1)] == 0){
            distances[RIGHT] = calculateDistance(xIndex+1, yIndex, currentTarget[0], currentTarget[1]);
        }
    }
    else if(currentDirection == RIGHT){
        if(xIndex < BOARD_WIDTH - 1){
            if(paths[(yIndex - 1) * BOARD_WIDTH + xIndex] == 0){
                distances[UP] = calculateDistance(xIndex, yIndex-1, currentTarget[0], currentTarget[1]);
            }
            if(paths[(yIndex + 1) * BOARD_WIDTH + xIndex] == 0){
                distances[DOWN] = calculateDistance(xIndex, yIndex+1, currentTarget[0], currentTarget[1]);
            }
            if(paths[yIndex * BOARD_WIDTH + (xIndex+1)] == 0){
            distances[RIGHT] = calculateDistance(xIndex+1, yIndex, currentTarget[0], currentTarget[1]);
        }
        }
        else{
            distances[RIGHT] = 0;
        }
    }

    for(int i = 0; i < 4; i++){
        if(distances[i] < minDistance){
            minDistance = distances[i];
            index = i;
        }
    }

    switch(index){
    case 0:
        currentDirection = UP;
        break;
    case 1:
        currentDirection = LEFT;
        break;
    case 2:
        currentDirection = DOWN;
        break;
    case 3:
        currentDirection = RIGHT;
        break;
    default:
        break;
    }
}

float Ghost::calculateDistance(int x1, int y1, int x2, int y2){
    return qSqrt(qPow(x1 - x2, 2) + qPow(y1 - y2, 2));
}

void Ghost::arrayReset(){
    distances[UP] = 1000;
    distances[LEFT] = 1000;
    distances[DOWN] = 1000;
    distances[RIGHT] = 1000;
}

void Ghost::move(){
    switch(currentDirection){
    case UP:
        setPos(x(), y() - STEP);
        if(((int)y() - OFFSET) % BLOCK_SIZE == 0){
            yIndex--;
        }
        break;
    case LEFT:
        setPos(x() - STEP, y());
        if(x() <= -GHOST_SIZE){
            setPos(BOARD_WIDTH * BLOCK_SIZE - GHOST_SIZE - OFFSET, y());
            xIndex = BOARD_WIDTH - 1;
        }
        else{
            if(((int)x() - OFFSET) % BLOCK_SIZE == 0){
                xIndex--;
            }
        }
        break;
    case DOWN:
        setPos(x(), y() + STEP);
        if(((int)y() - OFFSET) % BLOCK_SIZE == 0){
            yIndex++;
        }
        break;
    case RIGHT:
        setPos(x() + STEP, y());
        if(x() >= BOARD_WIDTH * BLOCK_SIZE){
            setPos(OFFSET, y());
            xIndex = 0;
        }
        else{
            if(((int)x() - OFFSET) % BLOCK_SIZE == 0){
                xIndex++;
            }
        }
        break;
    default:
        break;
    }
}