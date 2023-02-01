#pragma once
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>

class Ghost : public QObject, public QGraphicsRectItem{
    Q_OBJECT
  public:
    QTimer* collidedTimer;
    void setXIndex(int givenIndex);
    void setYIndex(int givenIndex);
  public slots:
    void playerGhostCollision();

  signals:
    void gameOverSignal();

  protected:
    const int GHOST_SIZE = 16;
    //const int STEP = 5;
    int xIndex;
    int yIndex;
};