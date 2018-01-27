#include "z_length_reducer.h"
#include  "z_gui_game.h"
#include "z_score.h"

void z_length_reducer::collect(z_GUI_Game *game)
{
    //removing one point of snake and life-=1 TWICE (one point should be removed regularly)
    point ce;
    ce=game->game->getboard().getsnake().getplist().takeLast();
    if(game->game->getboard().getsnake().getplist().isEmpty())
    {

        if(game->game->getboard().getperson().getlife().getlives()>1)
        {
            game->game->getboard().getsnake().getplist().push_back(ce);
            game->game->getboard().getperson().getlife().updatelife();
        }
        else
        {
            game->setingame(false) ;

        }
        return;
    }
    ce=game->game->getboard().getsnake().getplist().takeLast();
    if(game->game->getboard().getsnake().getplist().isEmpty())
    {
        if(game->game->getboard().getperson().getlife().getlives()>1)
        {
            game->game->getboard().getsnake().getplist().push_back(ce);
            game->game->getboard().getperson().getlife().updatelife();
        }
        else
        {
            game->setingame(false) ;

        }
        return;
    }
}




