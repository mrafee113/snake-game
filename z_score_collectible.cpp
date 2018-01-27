#include "z_score_collectible.h"
#include "z_gui_game.h"

z_score_collectible::z_score_collectible()
{

}

void z_score_collectible::collect(z_GUI_Game *game)
{
    game->game->getboard().getperson().getscore().setscore(game->game->getboard().getperson().getscore().getscore() + 20) ;
}
