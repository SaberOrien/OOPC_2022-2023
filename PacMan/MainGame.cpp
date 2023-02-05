#include "MainGame.h"
#include "Constants.h"
#include "Labirynth.h"
#include "Wall.h"
#include "Coin.h"
#include "Fruit.h"
#include "EndScreen.h"
#include <QTimer>

#include <QDebug>

MainGame::MainGame(){
    numOfCoins = 0;
    stateChanges = 0;
    graphicsSetUp();
    startUpPlayer();

    score = new Score();
    scene->addItem(score);

    blinky = new Blinky();
    connect(blinky, SIGNAL(gameOverSignal()), this, SLOT(gameOver()));
    
    pinky = new Pinky();
    connect(pinky, SIGNAL(gameOverSignal()), this, SLOT(gameOver()));

    inky = new Inky();
    connect(inky, SIGNAL(gameOverSignal()), this, SLOT(gameOver()));

    clyde = new Clyde();
    connect(clyde, SIGNAL(gameOverSignal()), this, SLOT(gameOver()));

    drawLabirynth();

    scene->addItem(player);
    scene->addItem(blinky);
    scene->addItem(pinky);
    scene->addItem(inky);
    scene->addItem(clyde);

    movementTimer = new QTimer();
    connect(movementTimer, SIGNAL(timeout()), this, SLOT(moveGhosts()));
    movementTimer->start(GHOST_MOVE_SPEED);

    gameTimer = new QTimer();
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(changeState()));
    gameTimer->start();

    show();
}

void MainGame::graphicsSetUp(){
    scene = new QGraphicsScene();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    setScene(scene);
}

void MainGame::startUpPlayer(){
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

void MainGame::drawLabirynth(){
    int box = 0;

    for(int h = 0; h < BOARD_HEIGHT; h++){
        for(int w = 0; w < BOARD_WIDTH; w++){
            box = labirynth[h * BOARD_WIDTH + w];

            switch(box){
            case 1:
            {
                Wall* brick = new Wall(0);
                brick->setPos(w * BLOCK_SIZE, h * BLOCK_SIZE);
                scene->addItem(brick);
            } break;
            case 9:
            {
                Wall* brick = new Wall(1);
                brick->setPos(w * BLOCK_SIZE, h * BLOCK_SIZE);
                scene->addItem(brick);
            } break;
            case 8:
            {
                player->setPos(w * BLOCK_SIZE + OFFSET, h * BLOCK_SIZE + OFFSET);
                player->setXIndex(w);
                player->setYIndex(h);
            } break;
            case 2:
            {
                Coin* coin = new Coin();
                numOfCoins++;
                connect(coin, SIGNAL(collectedCoinSignal(int)), this, SLOT(coinCollected(int)));
                coin->setPos(w * BLOCK_SIZE + (BLOCK_SIZE - coin->getSize())/2, h * BLOCK_SIZE + (BLOCK_SIZE - coin->getSize())/2);
                scene->addItem(coin);
            } break;
            case 3:
            {
                Fruit* fruit = new Fruit();
                numOfCoins++;
                connect(fruit, SIGNAL(collectedFruitSignal(int)), this, SLOT(fruitCollected(int)));
                fruit->setPos(w * BLOCK_SIZE + (BLOCK_SIZE - fruit->getSize())/2, h * BLOCK_SIZE + (BLOCK_SIZE - fruit->getSize())/2);
                scene->addItem(fruit);
            } break;
            case 4:
            {
                blinky->setXIndex(w);
                blinky->setYIndex(h);   
                connect(blinky, SIGNAL(ghostEatenSignal(int)), this, SLOT(eatenGhost(int)));       
                blinky->setPos(w * BLOCK_SIZE + OFFSET, h * BLOCK_SIZE + OFFSET);
            } break;
            case 5:
            {
                pinky->setXIndex(w);
                pinky->setYIndex(h);
                connect(pinky, SIGNAL(ghostEatenSignal(int)), this, SLOT(eatenGhost(int)));
                pinky->setPos(w * BLOCK_SIZE + OFFSET, h * BLOCK_SIZE + OFFSET);
            } break;
            case 6:
            {
                inky->setXIndex(w);
                inky->setYIndex(h);
                connect(inky, SIGNAL(ghostEatenSignal(int)), this, SLOT(eatenGhost(int)));
                inky->setPos(w * BLOCK_SIZE + OFFSET, h * BLOCK_SIZE + OFFSET);
            } break;
            case 7:
            {
                clyde->setXIndex(w);
                clyde->setYIndex(h);
                connect(clyde, SIGNAL(ghostEatenSignal(int)), this, SLOT(eatenGhost(int)));
                clyde->setPos(w * BLOCK_SIZE + OFFSET, h * BLOCK_SIZE + OFFSET);
            } break;
            default: 
                break;
            }
        }
    }
}

void MainGame::coinCollected(int points){
    numOfCoins--;
    score->increase(points);

    if(numOfCoins == 0){
        win();
    }
}

void MainGame::fruitCollected(int points){
    numOfCoins--;
    score->increase(points);

    blinky->setCurrentState(3);
    pinky->setCurrentState(3);
    inky->setCurrentState(3);
    clyde->setCurrentState(3);

    gameTimer->setInterval(FRIGNTEN_TIME);

    if(numOfCoins == 0){
        win();
    }
}

void MainGame::eatenGhost(int points){
    score->increase(points);
}

void MainGame::win(){
    clearScreen();
    Ending* win = new Ending("Victory", 1);
    scene->addItem(win);
}

void MainGame::gameOver(){
    clearScreen();
    Ending* lose = new Ending("Game Over!", 0);
    scene->addItem(lose);
}

void MainGame::clearScreen(){
    player->playerMoveTimer->stop();

    movementTimer->stop();
    gameTimer->stop();

    blinky->collidedTimer->stop();
    pinky->collidedTimer->stop();
    inky->collidedTimer->stop();
    clyde->collidedTimer->stop();

    QGraphicsRectItem* background = new QGraphicsRectItem(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    background->setBrush(QBrush(Qt::black));
    scene->addItem(background);
}

void MainGame::moveGhosts(){
    blinky->determineBehaviour(player->getXIndex(), player->getYIndex());
    pinky->determineBehaviour(player->getXIndex(), player->getYIndex(), player->getCurrentDirection());
    inky->determineBehaviour(player->getXIndex(), player->getYIndex(), player->getCurrentDirection(), blinky->getXIndex(), blinky->getYIndex());
    clyde->determineBehaviour(player->getXIndex(), player->getYIndex());
}

void MainGame::changeState(){
    if(stateChanges % 2 == 0){
        if(blinky->getCurrentState() != 2){
            blinky->setCurrentState(0);
        }
        if(pinky->getCurrentState() != 2){
            pinky->setCurrentState(0);
        }
        if(inky->getCurrentState() != 2){
            inky->setCurrentState(0);
        }
        if(clyde->getCurrentState() != 2){
            clyde->setCurrentState(0);
        }
        gameTimer->setInterval(CHASE_TIME);
    }
    else{
        if(blinky->getCurrentState() != 2){
            blinky->setCurrentState(1);
        }
        if(pinky->getCurrentState() != 2){
            pinky->setCurrentState(1);
        }
        if(inky->getCurrentState() != 2){
            inky->setCurrentState(1);
        }
        if(clyde->getCurrentState() != 2){
            clyde->setCurrentState(1);
        }
        gameTimer->setInterval(SCATTER_TIME);
    }
    stateChanges++;
}