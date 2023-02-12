#include "Player.h"
#include <QBrush>
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include "Wall.h"

Player::Player(){
    setRect(0, 0, PLAYER_SIZE, PLAYER_SIZE);
    setBrush(QBrush(Qt::yellow, Qt::SolidPattern));    
    playerMoveTimer = new QTimer();
    connect(playerMoveTimer, SIGNAL(timeout()), this, SLOT(move()));
    playerMoveTimer->start(50);
}

void Player::setXIndex(const int& givenIndex){
    xIndex = givenIndex;
}

void Player::setYIndex(const int& givenIndex){
    yIndex = givenIndex;
}

int Player::getXIndex() const{
    return xIndex;
}

int Player::getYIndex() const{
    return yIndex;
}

int Player::getCurrentDirection() const{
    return currentDirection;
}

void Player::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Up){
        currentDirection = UP;
    }
    else if(event->key() == Qt::Key_Down){
        currentDirection = DOWN;
    }
    else if(event->key() == Qt::Key_Left){
        currentDirection = LEFT;
    }
    else if(event->key() == Qt::Key_Right){
        currentDirection = RIGHT;
    }
}

void Player::move(){
    switch(currentDirection){
        case UP:
        {
            handleMoveUp();
        } break;
        case DOWN:
        {
            handleMoveDown();
        } break;
        case LEFT:
        {
            handleMoveLeft();
        } break;
        case RIGHT:
        {
            handleMoveRight();
        } break;
        default:
            break;
    }
}

bool Player::checkCollisionWithWall() const{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Wall)){
            return true;
        }
    }
    return false;
}

void Player::handleMoveUp(){
    setPos(x(), y() - STEP);
    if(checkCollisionWithWall() == false){
        yIndex = (y() - OFFSET) / BLOCK_SIZE;
        previousDirection = UP;
        setStartAngle(5*360); //up
        setSpanAngle(14*360);
    }
    else{
        setPos(x(), y() + STEP);
        if(previousDirection == RIGHT){
            handleMoveRight();
        }
        else if(previousDirection == LEFT){
            handleMoveLeft();
        }
    }
}

void Player::handleMoveDown(){
    setPos(x(), y() + STEP);
    if(checkCollisionWithWall() == false){
        yIndex = (y() - OFFSET) / BLOCK_SIZE;
        previousDirection = DOWN;
        setStartAngle(13*360); //down
        setSpanAngle(14*360);
    }
    else{
        setPos(x(), y() - STEP);
        if(previousDirection == RIGHT){
            handleMoveRight();
        }
        else if(previousDirection == LEFT){
            handleMoveLeft();
        }
    }
}

void Player::handleMoveRight(){
    setPos(x() + STEP, y());
    if(x() + PLAYER_SIZE/2 > (BLOCK_SIZE * BOARD_WIDTH)){
        setPos(OFFSET, y());
        xIndex = 0;
    }
    else if(checkCollisionWithWall() == false){
        xIndex = (x() - OFFSET) / BLOCK_SIZE;
        previousDirection = RIGHT;
        setStartAngle(1*360); //right
        setSpanAngle(14*360);
    }
    else{
        setPos(x() - STEP, y());
        if(previousDirection == UP){
            handleMoveUp();
        }
        else if(previousDirection == DOWN){
            handleMoveDown();
        }
    }
}

void Player::handleMoveLeft(){
    setPos(x() - STEP, y());
    if(x() + PLAYER_SIZE < 0){
        setPos((BLOCK_SIZE * BOARD_WIDTH) - (PLAYER_SIZE + OFFSET) , y());
        xIndex = BOARD_WIDTH - 1;
    }
    else if(checkCollisionWithWall() == false){
        xIndex = (x() - OFFSET) / BLOCK_SIZE;
        previousDirection = LEFT;
        setStartAngle(9*360); //left
        setSpanAngle(14*360);
    }
    else{
        setPos(x() + STEP, y());
        if(previousDirection == UP){
            handleMoveUp();
        }
        else if(previousDirection == DOWN){
            handleMoveDown();
        }
    }
}