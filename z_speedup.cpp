#include "z_speedup.h"
class z_game ;
#include "z_gui_game.h"
z_speedup::z_speedup()
{

}

void z_speedup::collect (z_GUI_Game * game)
{
    if ( game->game->getifspeedupeaten() == 0 )
    {
        game->game->setifspeedupeaten(1) ;
    }
}
