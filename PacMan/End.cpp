#include "End.h"
#include <QFont>
#include "Constants.h"

Ending::Ending(std::string msg, int option, QGraphicsItem* parent) : QGraphicsTextItem(parent){
    setPlainText(QString::fromStdString(msg));
    if(option == 1){
        setDefaultTextColor(Qt::green);
    }
    else if(option == 0){
        setDefaultTextColor(Qt::red);
    }
    setFont(QFont("OldEnglish", 50));
    setPos((SCREEN_WIDTH - boundingRect().width())/2, SCREEN_WIDTH/3 - boundingRect().height());
}