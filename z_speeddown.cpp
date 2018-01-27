#include "z_speeddown.h"
class z_game ;
#include "z_gui_game.h"
z_speeddown::z_speeddown()
{

}

void z_speeddown::collect (z_GUI_Game * game)
{
    if ( game->game->getifspeeddowneaten() == 0 )
    {
        game->game->setifspeeddowneaten(1) ;
    }
}
