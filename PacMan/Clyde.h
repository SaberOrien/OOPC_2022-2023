#pragma once

#include "Ghost.h"

class Clyde : public Ghost {
    Q_OBJECT
  public:
    Clyde();
  
  private:
    int PLAYER_RADIUS = 5;
    void setTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex);
};