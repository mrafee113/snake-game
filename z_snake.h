#ifndef Z_SNAKE_H
#define Z_SNAKE_H

#include "z_score.h"
#include "z_collectible.h"
#include "z_life.h"

#include <iostream>
#include <QList>
using namespace std;

struct point
{
    int i;
    int j;
};

class z_snake
{
    QList<point>   plist;
public:
    char dir; // too many set&get reqs // no time!
    //setter&getter
    QList<point> & getplist();
    ///

    z_snake();

    bool move (int n ,z_GUI_Game *getGame,int margin );
};

#endif // Z_SNAKE_H
