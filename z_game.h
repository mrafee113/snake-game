#ifndef Z_GAME_H
#define Z_GAME_H
#include "z_board.h"
#include "z_snake.h"
//#include <windows.h>
//#include <conio.h>
#include <QTextStream>
#include <QTimer>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>

class z_game
{
    z_board board;
    z_snake snake;
    bool ifpoisoneaten ;
    bool ifspeedupeaten ;
    bool ifspeeddowneaten;
    int spd ;
    int boardsize ;
public :
    //setter&getter
    int& getboardsize(){return boardsize;}
    void setboardsize(int get){boardsize = get ;}
    z_board& getboard();
    z_snake& getsnake();
    bool& getifpoisoneaten();
    void setifpoisoneaten( bool get );
    bool& getifspeedupeaten();
    void setifspeedupeaten( bool get );
    bool& getifspeeddowneaten();
    void setifspeeddowneaten( bool get );
    int& getspd();
    void setspd(int get);
    ///

    z_game();
};

#endif // Z_GAME_H

