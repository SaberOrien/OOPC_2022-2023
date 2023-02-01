#include "Wall.h"
#include "Constants.h"
#include <QBrush>

Wall::Wall(){
    setRect(0, 0, BLOCK_SIZE, BLOCK_SIZE);
    setBrush(QBrush(Qt::cyan, Qt::SolidPattern));
}