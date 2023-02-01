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
    graphicsSetUp();
    startUpPlayer();

    score = new Score();
    scene->addItem(score);

    blinky = new Blinky();
    connect(blinky, SIGNAL(gameOverSignal()), this, SLOT(gameOver()));
    scene->addItem(blinky);
    drawLabirynth();
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
    scene->addItem(player);
}

void MainGame::drawLabirynth(){
    int box = 0;

    for(int h = 0; h < BOARD_HEIGHT; h++){
        for(int w = 0; w < BOARD_WIDTH; w++){
            box = labirynth[h * BOARD_WIDTH + w];

            switch(box){
            case 1:
            {
                Wall* brick = new Wall();
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
                blinky->setPos(w * BLOCK_SIZE + OFFSET, h * BLOCK_SIZE + OFFSET);
            }
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

    if(numOfCoins == 0){
        win();
    }
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
    blinky->collidedTimer->stop();
    QGraphicsRectItem* background = new QGraphicsRectItem(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    background->setBrush(QBrush(Qt::black));
    scene->addItem(background);
}