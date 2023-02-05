#pragma once

#include "Ghost.h"

class Inky : public Ghost {
    Q_OBJECT
  public:
    Inky();

  private:
    void resetColor();
    void determineChaseTarget(int playerXIndex, int playerYIndex, int playerDirection, int blinkyXIndex, int blinkyYIndex);
    int getIndex(int a, int b, int mode);
};