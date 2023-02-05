#pragma once
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem{
  public:
    Score(QGraphicsItem * parent=0);
    void increase(int byPoints);
    int getScore();

  private:
    int score;
};