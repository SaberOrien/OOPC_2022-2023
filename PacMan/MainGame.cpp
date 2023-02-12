#include "MainGame.h"
#include "Constants.h"
#include "Map.h"
#include "Wall.h"
#include "Coin.h"
#include "Fruit.h"
#include "End.h"

#include <QTimer>
#include <QDebug>
MainGame::MainGame(){
    numOfCoins = 0;
    stateChanges = 0;

    graphicsSetUp();
    startUpPlayer();

    score = new Score();
    scene->addItem(score);

    startUpGhosts();    

    drawMap();

    addItemsToTheScene();

    moveGhostsTimer = new QTimer();
    connect(moveGhostsTimer, SIGNAL(timeout()), this, SLOT(moveGhosts()));
    moveGhostsTimer->start(GHOST_MOVE_SPEED);

    changeStatesTimer = new QTimer();
    connect(changeStatesTimer, SIGNAL(timeout()), this, SLOT(changeState()));
    changeStatesTimer->start();

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

void MainGame::startUpGhosts(){
    blinky = new Blinky();
    pinky = new Pinky();
    inky = new Inky();
    clyde = new Clyde();

    ghosts[0] = blinky;
    ghosts[1] = pinky;
    ghosts[2] = inky;
    ghosts[3] = clyde;

    for(int ghost = 0; ghost < 4; ghost++){
        connect(ghosts[ghost], SIGNAL(gameOverSignal()), this, SLOT(gameOver()));
    }
}

void MainGame::drawMap(){
    int pixel = 0;

    for(int height = 0; height < BOARD_HEIGHT; height++){
        for(int width = 0; width < BOARD_WIDTH; width++){
            pixel = map[height * BOARD_WIDTH + width];
            if(pixel == 1)
            {
                Wall* brick = new Wall(0);
                brick->setPos(width * BLOCK_SIZE, height * BLOCK_SIZE);
                scene->addItem(brick);
            }
            else if(pixel == 2)
            {
                Coin* coin = new Coin();
                numOfCoins++;
                connect(coin, SIGNAL(collectedCoinSignal(int)), this, SLOT(coinCollected(int)));
                coin->setPos(width * BLOCK_SIZE + (BLOCK_SIZE - coin->getSize())/2, height * BLOCK_SIZE + (BLOCK_SIZE - coin->getSize())/2);
                scene->addItem(coin);
            }
            else if(pixel == 3)
            {
                Fruit* fruit = new Fruit();
                numOfCoins++;
                connect(fruit, SIGNAL(collectedFruitSignal(int)), this, SLOT(fruitCollected(int)));
                fruit->setPos(width * BLOCK_SIZE + (BLOCK_SIZE - fruit->getSize())/2, height * BLOCK_SIZE + (BLOCK_SIZE - fruit->getSize())/2);
                scene->addItem(fruit);
            } 
            else if(pixel == 4)
            {
                Wall* brick = new Wall(1);
                brick->setPos(width * BLOCK_SIZE, height * BLOCK_SIZE);
                scene->addItem(brick);
            }
            else if(pixel == 5)
            {
                player->setPos(width * BLOCK_SIZE + OFFSET, height * BLOCK_SIZE + OFFSET);
                player->setXIndex(width);
                player->setYIndex(height);
            }
            else if(pixel == 6)
            {
                setUpGhost(blinky, width, height);
            } 
            else if(pixel == 7)
            {
                setUpGhost(pinky, width, height);
            } 
            else if(pixel == 8)
            {
                setUpGhost(inky, width, height);
            } 
            else if(pixel == 9)
            {
                setUpGhost(clyde, width, height);
            }
        }
    }
}

void MainGame::setUpGhost(Ghost* ghost, int width, int height){
    ghost->setXIndex(width);
    ghost->setYIndex(height);
    connect(ghost, SIGNAL(ghostEatenSignal(int)), this, SLOT(eatenGhost(int)));
    ghost->setPos(width * BLOCK_SIZE + OFFSET, height * BLOCK_SIZE + OFFSET);
}

void MainGame::addItemsToTheScene(){
    scene->addItem(player);
    for(int ghost = 0; ghost < 4; ghost++){
        scene->addItem(ghosts[ghost]);
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

    for(int ghost = 0; ghost < 4; ghost++){
        ghosts[ghost]->setCurrentState(3);
    }
    changeStatesTimer->setInterval(FRIGNTEN_TIME);

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

    moveGhostsTimer->stop();
    changeStatesTimer->stop();

    for(int ghost = 0; ghost < 4; ghost++){
        ghosts[ghost]->collidedTimer->stop();
    }

    QGraphicsRectItem* background = new QGraphicsRectItem(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    background->setBrush(QBrush(Qt::black));
    scene->addItem(background);
}

void MainGame::moveGhosts(){
    blinky->takeAction(player->getXIndex(), player->getYIndex());
    pinky->takeAction(player->getXIndex(), player->getYIndex(), player->getCurrentDirection());
    inky->takeAction(player->getXIndex(), player->getYIndex(), player->getCurrentDirection(), blinky->getXIndex(), blinky->getYIndex());
    clyde->takeAction(player->getXIndex(), player->getYIndex()); 
}


void MainGame::changeState(){
    if(stateChanges % 2 == 0){
        for(int ghost = 0; ghost < 4; ghost++){
            if(ghosts[ghost]->getCurrentState() != 2){
                ghosts[ghost]->setCurrentState(0);
            }
        }
        changeStatesTimer->setInterval(CHASE_TIME);
    }
    else{
        for(int ghost = 0; ghost < 4; ghost++){
            if(ghosts[ghost]->getCurrentState() != 3){
                ghosts[ghost]->setCurrentState(1);
            }
        }
        changeStatesTimer->setInterval(SCATTER_TIME);
    }
    stateChanges++;
}