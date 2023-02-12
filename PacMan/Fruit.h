#pragma once
#include <QObject>
#include <QGraphicsEllipseItem>

class Fruit : public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
  public:
    Fruit();
    int getSize();
    int getPoints();

  public slots:
    void playerFruitCollision();
  signals:
    void collectedFruitSignal(int points);
  private:
    const int FRUIT_SIZE = 12;
    const int POINTS = 50;
};