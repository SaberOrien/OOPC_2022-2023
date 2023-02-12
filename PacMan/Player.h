#pragma once
#include <QObject>
#include <QGraphicsEllipseItem>
#include "Constants.h"


class Player : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
  public:
    QTimer* playerMoveTimer;
    Player();
    void keyPressEvent(QKeyEvent* event);
    void setXIndex(const int& givenIndex);
    void setYIndex(const int& givenIndex);

    int getXIndex() const;
    int getYIndex() const;
    int getCurrentDirection() const;
  private slots:
    void move();
  private:
    Direction currentDirection;
    Direction previousDirection;
    const int PLAYER_SIZE = 16;
    const int STEP = 5;
    int xIndex;
    int yIndex;

    bool checkCollisionWithWall() const;
    void handleMoveUp();
    void handleMoveDown();
    void handleMoveLeft();
    void handleMoveRight();
};