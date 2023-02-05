#include <QApplication>
#include "MainGame.h"

int main(int argc, char* argv[]){
    QApplication PacMan(argc, argv);

    MainGame* game = new MainGame();
    game->show();

    return PacMan.exec();
}