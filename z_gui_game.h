#ifndef Z_GUI_GAME_H
#define Z_GUI_GAME_H
#include "z_board.h"
#include "z_snake.h"
#include "z_game.h"


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <QApplication>
#include <QPainter>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

using namespace std;



#include "z_gui_gameover.h"
class z_GUI_Game : public QWidget
{
    z_GUI_gameover *over ;
    QImage *Collectible , *head , *body , *wall ;
    QGridLayout * grid ;
    int Delay ;
    int timerId ;
    int margin ;
    bool ingame ;
public :
    z_game* game ;//too many usages! no time!
    //setter&getter
    int& gettimerId(){return timerId;}
    void settimerId(int get){timerId = get ;}
    int& getmargin(){return margin ;}
    void setmargin(int get){margin = get ;}
    bool& getingame(){return ingame;}
    void setingame(bool get){ingame = get ;}
    ///

    z_GUI_Game(QWidget* parent=0);

    void paintEvent(QPaintEvent * e);
    void timerEvent(QTimerEvent* e);
    void keyPressEvent(QKeyEvent *e);
};

#endif // Z_GUI_GAME_H
