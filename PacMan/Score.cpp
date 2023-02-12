#include "Score.h"
#include <QFont>
#include "Constants.h"

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent){
    score = 0;
    setPos(BLOCK_SIZE * BOARD_WIDTH + 10, 10);
    setPlainText("Score: "+ QString::number(score));
    setDefaultTextColor(QColor(207, 181, 59, 255));
    setFont(QFont("OldEnglish", 25));
}

void Score::increase(int byPoints){
    score += byPoints;
    setPlainText("Score: "+ QString::number(score));
}

int Score::getScore(){
    return score;
}