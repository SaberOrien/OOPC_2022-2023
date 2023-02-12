#pragma once

#include "Ghost.h"

class Inky : public Ghost {
    Q_OBJECT
  public:
    Inky();

  private:
    void setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex);
    int getXIndex(int player, int blinky);
    int getYIndex(int player, int blinky);
};