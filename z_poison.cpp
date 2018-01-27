#include "z_poison.h"
#include "z_game.h"
//#include <windows.h>

bool z_poison::getifpoisoneaten(){return ifpoisoneaten;}

z_poison::z_poison()
{
    ifpoisoneaten=0;

}
inline void z_poison::collect( z_game * game )
{
    if ( game->getifpoisoneaten() == 0 )
    {
        game->getboard().getperson().getscore().setscore(game->getboard().getperson().getscore().getscore()-10);
        game->setifpoisoneaten(1);
        return ;
    }

}

