#include "Blinky.h"
#include "Constants.h"
#include <QBrush>

Blinky::Blinky(){
    setRect(0, 0, GHOST_SIZE, GHOST_SIZE);
    setBrush(QBrush(Qt::red, Qt::SolidPattern));

    collidedTimer = new QTimer();
    connect(collidedTimer, SIGNAL(timeout()), this, SLOT(playerGhostCollision()));
    collidedTimer->start(START_TIMER);
}