#include "z_snake.h"
#include "z_speedup.h"
#include "z_length_reducer.h"
#include "z_poison.h"
#include "z_score_collectible.h"
#include "z_inverter.h"
#include "z_speeddown.h"

//#include <windows.h>
//#include <conio.h>
int CollectibleTimeout=0;
#include <z_gui_game.h>
QList<point> &z_snake::getplist(){return plist;}

z_snake::z_snake()
{
    point p;
    p.i=150;
    p.j=150;
    plist.push_back(p);
    dir='r';
}

bool z_snake::move(int n ,z_GUI_Game *getGame,int margin )
{
    point p =plist.at(0); // Snake Head

    //if((p.i<=10 || p.i>=(n-20) || p.j<=10 || p.j>=(n-20)))
    //Check Collision with wall
    if((p.i<=10+margin || p.i>=(n-10-10) || p.j<=10+margin || p.j>=(n-10-10)))
    {
        getGame->game->getboard().getperson().getlife().updatelife();
        if(getGame->game->getboard().getperson().getlife().getlives()<1)
            return false;
        else // Ghostmode
        {
            if ( p.i<=10+margin )
                p.i = n-10-10;

            if ( p.i >= (n-10-10)  )
                p.i = 10+margin ;

            if (p.j<=10+margin )
                p.j = n-10-10  ;

            if ( p.j>=(n-10-10) )
                p.j = 10+margin ;

            p.i=(rand()%(n-65))+32.5;
            p.i/=10;
            p.i*=10;
            p.j=(rand()%(n-65))+32.5;
            p.j/=10;
            p.j*=10;
        }
    }
    //lead snake's way
    {
        if(dir=='r')
        {

            p.i +=10;
            plist.push_front(p);

        }
        else if(dir=='l')
        {

            p.i -=10;
            plist.push_front(p);

        }
        else if(dir=='u')
        {
            p.j -=10;
            plist.push_front(p);

        }
        else if(dir=='d')
        {
            p.j +=10;
            plist.push_front(p);

        }
    }
    //check Collison with Self
    {
        for(int t=1 ; t<plist.size() ; t++)
        {
            if(p.i==plist.at(t).i && p.j==plist.at(t).j)
                return false ;
        }
    }

    CollectibleTimeout++;
    //check if collectible has been for more than 50 moves // timeout isn't implied to Food(Apple)
    if(CollectibleTimeout>=50 && getGame->game->getboard().getcollectible().getcoll().last().k!='o')
    {
        getGame->game->getboard().getcollectible().collectiblegenerate(n,getGame->game);
        CollectibleTimeout=0;
    }

    //check if Collectible Eaten
    if(getGame->game->getboard().getcollectible().getcoll().last().i== p.i && getGame->game->getboard().getcollectible().getcoll().last().j==p.j)
    {
        CollectibleTimeout=0;//init timeout for new Collectible
        z_collectible *  c;
        //calling Virtual Collect for the collectible to take effect
        {
            if(getGame->game->getboard().getcollectible().getcoll().last().k=='U')
            {
                c=new z_speedup;
                c->collect(getGame) ;
            }
            if(getGame->game->getboard().getcollectible().getcoll().last().k=='L')
            {
                c=new  z_length_reducer;
                c->collect(getGame);
            }
            if(getGame->game->getboard().getcollectible().getcoll().last().k=='D')
            {
                c= new z_speeddown ;
                c->collect(getGame) ;
            }
            if(getGame->game->getboard().getcollectible().getcoll().last().k=='*')
            {
                c = new z_poison ;
                c->collect(getGame) ;
                plist.removeLast();
            }
            if(getGame->game->getboard().getcollectible().getcoll().last().k=='+')
            {
                c = new z_score_collectible ;
                c->collect(getGame) ;

            }
            if(getGame->game->getboard().getcollectible().getcoll().last().k=='I')
            {
                c=new z_inverter;
                c->collect(getGame);
            }
        }
        //score update for collectible eaten
        if(getGame->game->getboard().getcollectible().getcoll().last().k !='L')//getting more score isn't implied to Legnth_Reducer
            getGame->game->getboard().getperson().getscore().update_score(&getGame->game->getboard().getperson().getlife());
        //Generate a new Collectible // Random longtitude & latitude
        getGame->game->getboard().getcollectible().collectiblegenerate(n,getGame->game);
    }
    else
        plist.removeLast(); //removing the last dot of snake if a collectible has not been eaten // we added a dot when leading the way
    return true;
}
