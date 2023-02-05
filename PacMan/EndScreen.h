#pragma once
#include <QGraphicsTextItem>
#include <string>

class Ending : public QGraphicsTextItem {
  public:
    Ending(std::string msg, int option, QGraphicsItem* parent=0);
};