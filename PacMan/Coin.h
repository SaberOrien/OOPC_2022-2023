#pragma once
#include <QObject>
#include <QGraphicsEllipseItem>

class Coin : public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
  public:
    Coin();
    int getSize();
    int getPoints();

  public slots:
    void playerCoinCollision();
    
  signals:
    void collectedCoinSignal(int points);

  private:
    const int COIN_SIZE = 6;
    const int POINTS = 10;
};