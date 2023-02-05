#pragma once

#include "Ghost.h"

class Clyde : public Ghost {
    Q_OBJECT
  public:
    Clyde();
  
  private:
    int PLAYER_RADIUS = 8;
    void resetColor();
    void determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex);
};