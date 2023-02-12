#pragma once
#include "Ghost.h"

class Pinky : public Ghost{
    Q_OBJECT
  public:
    Pinky();

  private:
    int CHASE_OFFSET = 4;
    void setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex);
};