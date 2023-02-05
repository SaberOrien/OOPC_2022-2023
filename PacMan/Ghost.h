#pragma once
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include "Constants.h"

class Ghost : public QObject, public QGraphicsRectItem{
    Q_OBJECT
  public:
    QTimer* collidedTimer;
    void setXIndex(int givenIndex);
    void setYIndex(int givenIndex);
    int getXIndex() const;
    int getYIndex() const;
    void determineBehaviour(int playerXIndex, int playerYIndex, int playerDirection = 0, int blinkyXIndex = 0, int blinkyYIndex = 0);
    void setCurrentState(int const& newState);
    int getCurrentState() const;
  public slots:
    void playerGhostCollision();

  signals:
    void gameOverSignal();
    void ghostEatenSignal(int points);

  protected:
    Direction currentDirection;
    enum State {CHASE, SCATTER, EATEN, FRIGHTENED};
    State currentState;

    const int GHOST_SIZE = 16;
    const int STEP = 5;
    const int POINTS = 200;
    int xIndex;
    int yIndex;
    int *chaseTarget;
    int *currentTarget;
    int *scatterTarget;
    int homeTarget[2] = {13, 11};
    float* distances;

    virtual void determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex) = 0;
    virtual void resetColor() = 0;

    void choosePath();
    float calculateDistance(int x1, int y1, int x2, int y2);
    void move();
    void arrayReset();
    void eatenBehaviour();
    void scatterBehaviour();
};