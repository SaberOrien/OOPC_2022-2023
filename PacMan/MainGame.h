#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include <QObject>
#include <QGraphicsView>
#include "Score.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"

class MainGame : public QGraphicsView{
    Q_OBJECT
  public:
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Blinky* blinky;
    Pinky* pinky;
    Inky* inky;
    Clyde* clyde;

    MainGame();

  public slots:
    void coinCollected(int points);
    void fruitCollected(int points);
    void gameOver();
    void moveGhosts();
    void changeState();
    void eatenGhost(int points);

  private:
    QTimer* movementTimer;
    QTimer* gameTimer;

    void graphicsSetUp();
    void startUpPlayer();
    void drawLabirynth();
    void win();
    void clearScreen();
    int numOfCoins;
    int stateChanges;

};