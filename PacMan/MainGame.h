#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include <QObject>
#include <QGraphicsView>
#include "Score.h"
#include "Blinky.h"

class MainGame : public QGraphicsView{
    Q_OBJECT
  public:
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Blinky* blinky;
    MainGame();
  public slots:
    void coinCollected(int points);
    void fruitCollected(int points);
    void gameOver();
  private:
    void graphicsSetUp();
    void startUpPlayer();
    void drawLabirynth();
    void win();
    void clearScreen();
    int numOfCoins;

};