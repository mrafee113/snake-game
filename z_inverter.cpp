#include "z_inverter.h"
#include "z_gui_game.h"
#include <unistd.h>

z_inverter::z_inverter()
{

}
void z_inverter::collect( z_GUI_Game* game )
{
    sleep(100);
    //Reverse the the List<point> plist which contains snake Longtitude&Latitude
    QList<point> temp;
    int  j=0;
    int q= game->game->getboard().getsnake().getplist().size();
    for(int i=game->game->getboard().getsnake().getplist().length()-1;i>=0;i--)
    {
        temp.insert(j,game->game->getboard().getsnake().getplist().at(i));
        j++;
    }
    game->game->getboard().getsnake().getplist().swap(temp);

    //change direction
    {
        if(game->game->getboard().getsnake().dir=='u')
        {
            if(game->game->getboard().getsnake().getplist().at(q-1).j == game->game->getboard().getsnake().getplist().at(q-2).j)
            {
                for(int w=0 ; w<q-1 ; w++)
                {
                    if(game->game->getboard().getsnake().getplist().at(q-1).i == game->game->getboard().getsnake().getplist().at(w).i)
                        return;
                }
            }
            game->game->getboard().getsnake().dir = 'd';
            return;
        }
        if(game->game->getboard().getsnake().dir=='d')
        {
            if(game->game->getboard().getsnake().getplist().at(q-1).j == game->game->getboard().getsnake().getplist().at(q-2).j)
            {
                for(int w=0 ; w<q-1 ; w++)
                {
                    if(game->game->getboard().getsnake().getplist().at(q-1).i == game->game->getboard().getsnake().getplist().at(w).i)
                        return;
                }
            }
            game->game->getboard().getsnake().dir='u';
            return;
        }
        if(game->game->getboard().getsnake().dir=='l')
        {
            if(game->game->getboard().getsnake().getplist().at(q-1).j == game->game->getboard().getsnake().getplist().at(q-2).j)
            {
                for(int w=0 ; w<q-1 ; w++)
                {
                    if(game->game->getboard().getsnake().getplist().at(q-1).i == game->game->getboard().getsnake().getplist().at(w).i)
                        return;
                }
            }
            game->game->getboard().getsnake().dir='r';
            return;
        }
        if(game->game->getboard().getsnake().dir=='r')
        {
            if(game->game->getboard().getsnake().getplist().at(q-1).j == game->game->getboard().getsnake().getplist().at(q-2).j)
            {
                for(int w=0 ; w<q-1 ; w++)
                {
                    if(game->game->getboard().getsnake().getplist().at(q-1).i == game->game->getboard().getsnake().getplist().at(w).i)
                        return;
                }
            }
            game->game->getboard().getsnake().dir='l';
            return;
        }
    }

}



