#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include "Player.h"
#include "Score.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "Pinky.h"

class MainGame : public QGraphicsView{
    Q_OBJECT
  public:
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Blinky* blinky;
    Clyde* clyde;
    Inky* inky;
    Pinky* pinky;
    Ghost* ghosts[4];

    MainGame();

  public slots:
    void coinCollected(int points);
    void fruitCollected(int points);
    void gameOver();
    void moveGhosts();
    void changeState();
    void eatenGhost(int points);

  private:
    QTimer* moveGhostsTimer;
    QTimer* changeStatesTimer;

    void graphicsSetUp();
    void startUpPlayer();
    void drawMap();
    void addItemsToTheScene();
    void win();
    void clearScreen();
    void startUpGhosts();
    void setUpGhost(Ghost* ghost, int width, int height);

    int numOfCoins;
    int stateChanges;
};
