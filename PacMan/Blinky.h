#pragma once
#include "Ghost.h"

class Blinky : public Ghost{
    Q_OBJECT
  public:
    Blinky();
  private:
    void setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex);
};