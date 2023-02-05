#include "Wall.h"
#include "Constants.h"
#include <QBrush>

Wall::Wall(int mode){
    setRect(0, 0, BLOCK_SIZE, BLOCK_SIZE);
    if(mode == 1){
        setBrush(QBrush(QColor::fromRgb(160,82,45), Qt::SolidPattern));
    }
    else{
        setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));
    }
    
}